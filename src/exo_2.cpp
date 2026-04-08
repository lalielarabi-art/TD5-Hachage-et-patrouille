#include <iostream>
#include <unordered_set>

enum class Direction{
    Haut,
    Droite,
    Bas,
    Gauche,
};

struct Position{
    int x;
    int y;

    Position operator+=(Position const& b) {
        x += b.x;
        y += b.y;
        return *this;
    }

    Position operator+=(Direction dir){

        switch(dir){
            case Direction::Haut:
                y -= 1;
                break;
            case Direction::Droite:
                x +=1;
                break;
            case Direction::Bas:
                y +=1;
                break;
            case Direction::Gauche:
                x -=1;
                break;

        }
         return *this;
    }

};
namespace std {
    template <>
    struct hash<Position> {
        std::size_t operator()(const Position& pos) const {
            return pos.x^pos.y;
        }
    };
}
Position operator+(Position pos, Direction dir){
        pos += dir; 
        return pos;
    }

Direction turn_right(Direction dir){
    switch(dir){
        case Direction::Haut:
            dir=Direction::Droite;
            break;
        case Direction::Bas:
            dir=Direction::Gauche;
            break;
        case Direction::Gauche:
            dir=Direction::Haut;
            break;
        case Direction::Droite:
            dir=Direction::Bas;
            break;
    }
    return dir;
}

bool operator==(Position const& a, Position const& b) {
    return a.x == b.x && a.y == b.y;
}

std::ostream& operator<<(std::ostream& os, Position const& p) {
    return os << '(' << p.x << ", " << p.y << ')';
}

struct Input_Structure{
    Position init_pos;

    Direction init_dir;

    std::unordered_set <Position> obstacles ;

    int height;
    int width;

};


Input_Structure read_input(std::istream& input_stream){

    std::unordered_set <Position> filled_positions {};

    int width {0};
    int height{0};
    Position start_pos;

    int row{0};
    int col{0};


    for (std::string line{}; std::getline(input_stream, line, '\n') and line != "";) {
        for( col=0; col < static_cast<int>(line.size()); ++col){
            char cell=line[col];

            if (cell=='#'){
                filled_positions.insert(Position{col,row});
            }
            else if(cell=='^'){
                start_pos.x=col;
                start_pos.y=row;
            }
        }
        row ++;

    }

    width=col;
    height=row;

    return {
        start_pos,
        Direction::Haut,
        filled_positions,
        width,
        height,
    };
}

struct WalkResult {
    Position final_position;
    size_t steps_taken;
    std::unordered_set<Position> visited_positions;
};


WalkResult mouvement (Input_Structure map){
    Position current_pos {map.init_pos};

    Direction dir{map.init_dir};

    size_t steps_takens;

    std::unordered_set<Position> visited_positions{};

    while (current_pos.x>=0 && current_pos.x<=map.width && current_pos.y>=0 && current_pos.y<=map.height ){

        visited_positions.insert(current_pos);

        if(map.obstacles.find(current_pos + dir)!= map.obstacles.end()){
            current_pos += dir;
        }
        else{
            dir= turn_right(dir);
            current_pos += dir;
        }
        
        steps_takens +=1;
        
    }

    return {
        current_pos,
        steps_takens,
        visited_positions,
    };
}


int main(){
}