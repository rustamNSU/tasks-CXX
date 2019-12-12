#include "GameOfLife.h"

/**
 * This function reads initial configuration 
 * from input file
 * 
 * * - alive
 * _ - empty
 * 
 * example:
 * **_
 * __*
 * ***
 */
void GameOfLife::Fill( ifstream& input ){

    input >> this->row >> this->col;
    CurrentConfig = vector(row + 2,vector<bool>(col+2,0));
    for(int ir=0; ir<row; ir++){
        for(int ic=0; ic<col; ++ic){

            char cell;
            input >> cell;
            if(cell == 'O'){
                this->CurrentConfig[ir+1][ic+1] = 1;
            }
            else{
                this->CurrentConfig[ir+1][ic+1] = 0;
            }

        }
    }
    return;
}

void GameOfLife::next_generation()
{
    vector<vector<bool>> NextConfig = CurrentConfig;
    for(int ir=1; ir<row+1; ir++){
        for(int ic=1; ic<col+1; ++ic)
        {
            int sum = CurrentConfig[ir-1][ic-1]
                    + CurrentConfig[ir-1][ic]
                    + CurrentConfig[ir-1][ic+1]
                    + CurrentConfig[ir][ic-1]
                    + CurrentConfig[ir][ic+1]
                    + CurrentConfig[ir+1][ic-1]
                    + CurrentConfig[ir+1][ic]
                    + CurrentConfig[ir+1][ic+1];
            
            if(CurrentConfig[ir][ic]){
                if(sum<2 || sum>3){
                    NextConfig[ir][ic] = 0;
                }
                else{
                    NextConfig[ir][ic] = 1;
                }
            }
            else{
                if(sum == 3){
                    NextConfig[ir][ic] = 1;
                }
            }       
        }
    }
    CurrentConfig.swap(NextConfig);
    Generation++;
}

void GameOfLife::print()
{
    std::cout << "Generation = " << Generation << std::endl;
    for(int ir=1; ir<row+1; ir++){
        for(int ic=1; ic<col+1; ++ic){

            if(CurrentConfig[ir][ic]){
                std::cout << '*';
            }
            else{
                std::cout << ' ';
            }

        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}