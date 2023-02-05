//
// Created by Алексей on 21.01.2023.
//

#include "view_game.h"

view_game::view_game(RenderWindow *window, game *model): view(window), model(model),
View(FloatRect(0.f,0.f,800.f,600.f)){

    world_map map = model->get_map();
    string map_name = map.get_map_name();
    this->map.t.loadFromFile("../texture/"+map_name+".png");
    this->map.sprite.setTexture(this->map.t);

    hero* player = model->get_hero();
    string player_name = player->get_type();
    this->player.t.loadFromFile("../texture/"+player_name+".png");
    this->player.sprite.setTexture(this->player.t);
}

void view_game::draw_interface(int hp, int wp_now, int wp_total) {
    auto window = get_window();

    View.setCenter(sf::Vector2f(400, 300));
    window->setView(View);


    Font font;
    font.loadFromFile("C:/WINDOWS/Fonts/arial.ttf");

    string str_heal_point;
    str_heal_point = to_string(hp);

Text heal_point("", font, 20);
    heal_point.setPosition(View.getCenter().x - 165, View.getCenter().y - 200);
    heal_point.setString(L"Здоровье : "+str_heal_point);
    heal_point.setColor(Color::White);
    string str_wave_point_now;
    str_wave_point_now = to_string(wp_now);
    string str_wave_point_total;
    str_wave_point_total = to_string(wp_total);

Text wave_point("", font, 20);
    wave_point.setColor(Color::White);
    wave_point.setPosition(View.getCenter().x - 140, View.getCenter().y - 175);
    wave_point.setString(L"Волна " + str_wave_point_now + L" из " + str_wave_point_total);

    window->draw(heal_point);
    window->draw(wave_point);
}

int view_game::paint(vector<int> &ctrl_data) {

    auto window = get_window();
    int return_value = 0;

    if (ctrl_data[5] == 0){

        hero* player = model->get_hero();
        View.setCenter(sf::Vector2f(player->get_x(), player->get_y()));
        this->player.sprite.setPosition(player->get_x(), player->get_y());
        window->setView(View);

        check_enemy(); // достаём лиcт противников из модели и сверяем с нашим листом, если есть различия, то исправляем.
        check_projectile();

        window->draw(map.sprite);
        draw_enemy();
        window->draw(this->player.sprite);
        draw_projectile();

        world_map map1 = model->get_map();


        draw_interface(player->get_hp(), map1.get_wave_number(), map1.get_wave_count());
    }


    Texture win,lose, start, exit;
    lose.loadFromFile("../texture/bg_l.png");
    win.loadFromFile("../texture/bg_w.png");
    start.loadFromFile("../texture/start.png");
    exit.loadFromFile("../texture/exit.png");

    Sprite s_lose, s_win, s_start, s_exit;
    s_lose.setTexture(lose);
    s_win.setTexture(win);
    s_start.setTexture(start);
    s_exit.setTexture(exit);

    if (ctrl_data[5] == 1){  // win
        View.setCenter(sf::Vector2f(400, 300));
        window->setView(View);

        s_start.setPosition(300,290);
        s_exit.setPosition(300, 380);

        if(IntRect(300, 290, 150, 17).contains(ctrl_data[1], ctrl_data[2]) && ctrl_data[0]){
            return_value = 1;
        }
        else if(IntRect(300, 380, 125, 17).contains(ctrl_data[1], ctrl_data[2]) && ctrl_data[0]){
            return_value = -1;}

        window->draw(s_win);
        window->draw(s_start);
        window->draw(s_exit);
    }

    else if (ctrl_data[5] == -1) {  //lose
        View.setCenter(sf::Vector2f(400, 300));
        window->setView(View);

        s_start.setPosition(300,290);
        s_exit.setPosition(300, 380);

        if(IntRect(300, 290, 150, 17).contains(ctrl_data[1], ctrl_data[2]) && ctrl_data[0]){
            return_value = 1;
        }
        else if(IntRect(300, 380, 125, 17).contains(ctrl_data[1], ctrl_data[2]) && ctrl_data[0]){
            return_value = -1;}

        window->draw(s_lose);
        window->draw(s_start);
        window->draw(s_exit);
    }

    return return_value;

}

void view_game::check_enemy() {
    list<enemy> enemy_list = model->get_enemies();

    while (enemy_list.size() > enemies.size()) {
        enemies.push_back(texture());
    }
    while (enemy_list.size() < enemies.size()) {
        enemies.pop_back();
    }

    auto it2 = enemies.begin();
    for (auto it1 = enemy_list.begin(); it1 != enemy_list.end(); it1++) {
        int model_x = it1->get_x();
        int model_y = it1->get_y();
        double model_angle = it1->get_angle_of_rotation() * (360 / 3.14);
        string model_type = it1->get_type();
        int view_x = it2->sprite.getPosition().x;
        int view_y = it2->sprite.getPosition().y;
        string view_type = it2->type;
        double view_angle = it2->sprite.getRotation();

        if (model_x != view_x) {
            it2->sprite.setPosition(model_x, model_y);
        }
        if (model_y != view_y) {
            it2->sprite.setPosition(model_x, model_y);
        }
        if (model_angle != view_angle) {
            it2->sprite.setRotation(model_angle);
        }
        if (model_type != view_type) {
            it2->t.loadFromFile("../texture/" + model_type + ".png");
            it2->sprite.setTexture(it2->t);
            it2->type = model_type;
        }
        it2++;
    }
}

void view_game::check_projectile() {
    list<projectile *> projectile_list = model->get_projectiles();
    while (projectile_list.size() > proj_tile.size()) {
        proj_tile.push_back(texture());
    }
    while (projectile_list.size() < proj_tile.size()) {
        proj_tile.pop_back();
    }

    auto it2 = proj_tile.begin();
    for (auto it1 = projectile_list.begin(); it1 != projectile_list.end(); it1++) {
        int m_x = (*it1)->get_x();
        int m_y = (*it1)->get_y();
        double m_angle = (*it1)->get_angle_of_rotation();
        string m_type = (*it1)->get_type();
        int v_x = it2->sprite.getPosition().x;
        int v_y = it2->sprite.getPosition().y;
        double v_angle = it2->sprite.getRotation();
        string v_type = it2->type;

        if (m_x != v_x) {
            it2->sprite.move(m_x - v_x, 0);
        }
        if (m_y != v_y) {
            it2->sprite.move(0, m_y - v_y);
        }
        if (m_angle != v_angle) {
            it2->sprite.setRotation(m_angle - v_angle);
        }
        if (m_type != v_type) {
            it2->t.loadFromFile("../texture/" + m_type + ".png");
            it2->sprite.setTexture(it2->t);
            it2->type = m_type;
        }

        it2++;
    }
}

void view_game::draw_enemy()
{
    for(auto it1 = enemies.begin(); it1 != enemies.end(); it1++)
    {
        window->draw(it1->sprite);
    }
}
void view_game::draw_projectile()
{
    for(auto it1 = proj_tile.begin(); it1 != proj_tile.end(); it1++)
    {
        window->draw(it1->sprite);
    }
}