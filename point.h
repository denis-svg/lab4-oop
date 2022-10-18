#pragma once

class Point{
    private:
        int x;
        int y;
    public:
        Point(int x, int y){
            this->x = x;
            this->y = y;
        }
        Point(){
            this->x = 0;
            this->y = 0;
        }
        void setRow(int row){
            this->y = row;
        }
        void setCol(int col){
            this->x = col;
        }
        float getRow(){
            return this->y;
        }
        float getCol(){
            return this->x;
        }
};