#ifndef ACTOR_H
#define ACTOR_H

struct Inputs {  // We simplify amount of inputs acquired to one per tick
    bool hasInput;
    char input;
    Inputs() {
        hasInput = false;
        input = 0;
    }
};

class Actor {

public:
    Actor();
    Actor(const Actor &a);
    Actor(int x, int y) { pos_x = x; pos_y = y; };
    ~Actor();

    void set_pos_x(int pos) { pos_x = pos; }
    void set_pos_y(int pos) { pos_y = pos; }

    int get_pos_x() { return pos_x; }
    int get_pos_y() { return pos_y; }

    int get_actor_type() { return actor_type; }

    void move_left() { pos_x -= 1; }
    void move_right() { pos_x += 1; }

    // Note: remember that (0, 0) is the upper-left hand corner.
    void move_up() { pos_y -= 1; }
    void move_down() { pos_y += 1; }

    virtual void tick(Inputs inputs) {};

    void Destroy() { toDestroy = true; }

    bool toDestroy = false;
protected:
    int pos_x, pos_y;
    int actor_type = 0;


};


#endif