#include <string>
#include <fstream>
#include <tuple>
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

        structures::ArrayQueue<std::tuple<int, int>> pixel_queue{10000};

        int matrix_R[height * width] = {};
        int label = 1;

        for (int x = 0; x < height; x++) {
            for (int y = 0; y < width; y++) {

                char color = data_s[x * width + y];

                while (not pixel_queue.empty()) {

                    std::tuple<int, int> main_coordinate = pixel_queue.dequeue();

                    int i = std::get<0>(main_coordinate);
                    int j = std::get<1>(main_coordinate);

                    if (i > 0 && data_s[(i-1) * width + j] == '1' && matrix_R[(i-1) * width + j] == 0) {
                        matrix_R[(i-1) * width + j] = label;
                        pixel_queue.enqueue(std::make_tuple(i - 1, j));
                    }

                    if (j > 0 && data_s[i * width + j - 1] == '1' && matrix_R[i * width + j - 1] == 0) {
                        matrix_R[i * width + j - 1] = label;
                        pixel_queue.enqueue(std::make_tuple(i, j - 1));
                    }

                    if (i < height - 1 && data_s[(i+1) * width + j] == '1' && matrix_R[(i+1) * width + j] == 0) {
                        matrix_R[(i+1) * width + j] = label;
                        pixel_queue.enqueue(std::make_tuple(i + 1, j));
                    }

                    if (j < width - 1 && data_s[i * width + j + 1] == '1' && matrix_R[i * width + j + 1] == 0) {
                        matrix_R[i * width + j + 1] = label;
                        pixel_queue.enqueue(std::make_tuple(i, j + 1));
                    }

                }

                if (color == '1' and matrix_R[x * width + y] == 0) {

                    pixel_queue.enqueue(std::make_tuple(x, y));
                    matrix_R[x * width + y] = label;

                }
            }
        }       
    }
}