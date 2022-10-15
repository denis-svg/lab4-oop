#pragma once

class Point{
    private:
        float x;
        float y;
    public:
        Point(float x, float y){
            this->x = x;
            this->y = y;
        }
        Point(){
            this->x = 0;
            this->y = 0;
        }
        void setRow(float row){
            this->y = row;
        }
        void setCol(float col){
            this->x = col;
        }
        float getRow(){
            return this->y;
        }
        float getCol(){
            return this->x;
        }
};