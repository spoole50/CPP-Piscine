/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 18:52:24 by spoole            #+#    #+#             */
/*   Updated: 2020/01/24 13:52:51 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

void    start_game()
{
    int ch;
    clear();
    Player player1("Player One", (char*)"~}", 0, 5);
    getmaxyx(stdscr, player1.max_y, player1.max_x);
    GameInstance::level = 1;
    mvprintw(player1.max_y/2, 5, "Hello Welcome to FT_SPACEJAM press space to continue or esc to exit");
    mvprintw(player1.max_y/2 + 1, 5, "Arrow keys for movement, space for shooting, BOSS every 10 levels. Good Luck Cadet!");
    do
    {
        ch = getch();
    } while (ch != 32 && ch != 27);

    if (ch == 32)
        continue_game(player1);
    else
        exit_game();
}

void    exit_game(void)
{
    Enemy::clean();
    Bullet::clean();
    endwin();
    exit(0);
}

void    moveEnemies(void)
{
    if (Boss::isBoss)
    {
        if (time(NULL) - Boss::boss->cooldown > 2)
        {
            //Bullet::clean();
            Boss::boss->update(true);
            Boss::boss->cooldown = time(NULL);
        }
        else
            Boss::boss->update(false);
    }
    Enemy   *tene;
    Bullet  *tbull;
    for(int i = 0; i < MAX_SIZE; i++)
    {
        tbull = Bullet::BulletList[i];
        if (!Boss::isBoss)
        {
            tene = Enemy::enemyList[i];
            if (tene != NULL)
                tene->update();
        }
        if (tbull != NULL)
            tbull->update();
    }
}

void    makeEnemies(int playX)
{
    for (int i = 0; i < GameInstance::level; i++)
        Enemy::addEnemy(playX);
}

void    clean(void)
{
    Bullet::clean();
    Enemy::clean();
}

void    dead(Player &player1)
{
    int ch;
    clear();
    mvprintw(player1.max_y/2, 5, "You died HAHA, press space to try again or esc to exit");
    do
    {
        ch = getch();
    } while (ch != 32 && ch != 27);
    if (ch == 32)
    {
        GameInstance::level = 0;
        if (Boss::isBoss)
        {
            delete Boss::boss;
            Boss::boss = NULL;
        }
        player1.~Player();
        clean();
        start_game();
    }
    else
        exit_game();
}

void    checkCollisions(Player &player1)
{
    Enemy * tEne;
    Bullet * tBull;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        tEne = Enemy::enemyList[i];
        if (tEne != NULL)
        {
            if (tEne->ckCollision(&player1))
                dead(player1);
            for (int x = 0; x < MAX_SIZE; x++)
            {
                tBull = Bullet::BulletList[x];
                if (tBull != NULL)
                {
                    if (tBull->ckCollision(&player1))
                        dead(player1);
                    if (tBull->ckCollision(tEne))
                    {
                        Bullet::delIndex(x);
                        Enemy::delIndex(i);
                        player1.score++;
                    }
                }
            }
        }
    }
}

void    genBackground(void)
{
    Background  *temp;
    for (int i = 0; i < BACK_SIZE; i++)
    {
        temp = Background::map[i];
        if (temp == NULL)
            Background::addBackground(false);
        else
            temp->update();
    }
}

void    enemyCycle(int playX)
{
    if (GameInstance::cycle == 50)
    {
        if ((!Boss::isBoss))
        {
            makeEnemies(playX);
            if (GameInstance::rounds % 5 == 0)
                GameInstance::level++;
        }
        GameInstance::cycle = 0;
        GameInstance::rounds++;
    }
    else if (GameInstance::level % 10 == 0)
    {
        Boss::boss = new Boss(GameInstance::level);
        clean();
        GameInstance::level++;
    }
}

void    bossCollision(Player &player1)
{
    Bullet *temp;
    if (Boss::boss->ckCollision(&player1))
        dead(player1);
    for (int i = 0; i < MAX_SIZE && Boss::boss != NULL; i++)
    {
        temp = Bullet::BulletList[i];
        if (temp != NULL)
        {
            if (temp->direction == -1 && temp->ckCollision(&player1))
                dead(player1);
            if (temp->direction == 1 && Boss::boss->ckCollision(temp))
            {
                Boss::boss->hits--;
                Bullet::delIndex(i);
                if (Boss::boss->hits <= 0)
                {
                    delete Boss::boss;
                    Boss::boss = NULL;
                }
            }
        }
    }
}

void    continue_game(Player &player1)
{
    GameInstance::rounds = 0;
    GameInstance::cycle = 0;
    std::chrono::time_point<std::chrono::system_clock> t = std::chrono::system_clock::now();
    player1.y = player1.max_y/2;
    while (1)
    {
        getmaxyx(stdscr, player1.max_y, player1.max_x);
        clear();
        player1.userInput();
        genBackground();
        moveEnemies();
        if (!Boss::isBoss)
            checkCollisions(player1);
        else
            bossCollision(player1);
        player1.update();
        mvprintw(1, 2, "Player: %s\tPoints: %i\tLevel: %i\tTime(sec): %3i", player1.name.c_str(), player1.score, GameInstance::level, (int)(time(NULL) - mktime(player1.time)));
        enemyCycle(player1.x);
        box(stdscr, '|', '>');
        wrefresh(stdscr);
        t += std::chrono::milliseconds(33);
        std::this_thread::sleep_until(t);
        GameInstance::cycle++;
    }
    exit_game();
}

void    color(void)
{
    start_color();
    init_color(COLOR_WHITE, 500, 500, 500);
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);
}

int     main(void)
{
    initscr(); // Initialize Screem
    cbreak(); //One character at a time
    noecho(); //Supress automatic echoing of typed char
    nodelay(stdscr, TRUE); //allows getch() to work in non-blocking manner
    keypad(stdscr, TRUE); //Captures special keystrokes by getch()
    curs_set(FALSE); // Don't display a cursor

    color();
    srand(time(NULL));
    start_game();
    
    return (0);
}
