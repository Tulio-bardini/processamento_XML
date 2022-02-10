#include <string>
#include <fstream>
#include <tuple>
#include <vector>
#include "queue.h"
#include "tag_validator.h"

namespace counter {

    // Implementa o algoritimo vizinhança-4 nos seguintes passos:
    // 1 - Constroi uma matriz do tipo vetor com o tamanho necessário.
    // 2 - Percorre a matriz de string em busca do elemento '1'.
    // 3 - Adiciona na fila a posição do elemento encontrado (x,y).
    // 4 - Busca na vizinhança das posições da fila novos elementos '1'.
    // 5 - Adiciona na fila os novos elementos encontrados.
    // 6 - Quando a fila fica fazia, retoma a busca do elemento '1'.

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

                //realiza a busca na vizinhança dos elementos da fila
                while (not pixel_queue.empty()) {

                    std::tuple<int, int> main_coordinate = pixel_queue.dequeue();

                    int i = std::get<0>(main_coordinate);
                    int j = std::get<1>(main_coordinate);

                    // Verifica se o elemento acima é '1'
                    if (i > 0 && data_s[(i - 1) * width + j] == '1' && not R_matrix[i - 1][j]) {
                        R_matrix[i - 1][j] = true;
                        pixel_queue.enqueue(std::make_tuple(i - 1, j));
                    }

                    // Verifica se o elemento a esquerda é '1'
                    if (j > 0 && data_s[i * width + j - 1] == '1' && not R_matrix[i][j - 1]) {
                        R_matrix[i][j - 1] = true;
                        pixel_queue.enqueue(std::make_tuple(i, j - 1));
                    }

                    // Verifica se o elemento abaixo é '1'
                    if (i < height - 1 && data_s[(i + 1) * width + j] == '1' && not R_matrix[i + 1][j]) {
                        R_matrix[i + 1][j] = true;
                        pixel_queue.enqueue(std::make_tuple(i + 1, j));
                    }

                    // Verifica se o elemento a direita é '1'
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