#include <string>
#include <fstream>
#include <tuple>
#include <vector>
#include "queue.h"
#include "tag_validator.h"

namespace counter {

    int component_counter (const std::string width_s,
                            const std::string height_s,
                            const std::string data_s) {

        int width;
        int height;
        width = std::stoi(width_s);
        height = std::stoi(height_s);

        structures::ArrayQueue<std::tuple<int, int>> pixel_queue{1000000};

        std::vector<std::vector<bool>> R_matrix;

        for (int i = 0u; i < height; i++) {
            std::vector<bool> line;

            for (int j = 0; j < width; j++)
                line.push_back(false);

            R_matrix.push_back(line);
        }

        int label = 0;
        

        for (int x = 0; x < height; x++) {
            for (int y = 0; y < width; y++) {

                char color = data_s[x * width + y];

                while (not pixel_queue.empty()) {

                    std::tuple<int, int> main_coordinate = pixel_queue.dequeue();

                    int i = std::get<0>(main_coordinate);
                    int j = std::get<1>(main_coordinate);

                    if (i > 0 && data_s[(i - 1) * width + j] == '1' && not R_matrix[i - 1][j]) {
                        R_matrix[i - 1][j] = true;
                        pixel_queue.enqueue(std::make_tuple(i - 1, j));
                    }

                    if (j > 0 && data_s[i * width + j - 1] == '1' && not R_matrix[i][j - 1]) {
                        R_matrix[i][j - 1] = true;
                        pixel_queue.enqueue(std::make_tuple(i, j - 1));
                    }

                    if (i < height - 1 && data_s[(i + 1) * width + j] == '1' && not R_matrix[i + 1][j]) {
                        R_matrix[i + 1][j] = true;
                        pixel_queue.enqueue(std::make_tuple(i + 1, j));
                    }

                    if (j < width - 1 && data_s[i * width + j + 1] == '1' && not R_matrix[i][j+1]) {
                        R_matrix[i][j + 1] = true;
                        pixel_queue.enqueue(std::make_tuple(i, j + 1));
                    }

                }

                if (color == '1' && R_matrix[x][y] == false) {

                    label++;
                    pixel_queue.enqueue(std::make_tuple(x, y));
                    R_matrix[x][y] = true;

                }
            }
        }    
        return label;
    }
}