from gun_colors import *
from gun_object import *
from menu import *
from button import *
import random as rnd
import pygame as pg
import pygame.draw as pgd
import math as m
from level_1 import *
from level_2 import *
from level_3 import *

#checking if menu activated(if active - activate its buttons)
def buttons_activated(statement):
    if statement:
        return True
    else:
        return False
    
def level_1():
    targets = []
    targett = Target(800, 490, 20)
    targets.append(targett)
    count = 0
    pig_1 = Pig(800, 490, 20, 20, 0)
    all_sprites1.add(pig_1)
    pig_lvl1.add(pig_1)
    pig_1_gr = pg.sprite.GroupSingle()
    pig_1_gr.add(pig_1)
    all_sprites1.update()
    screen.fill(BLACK)
    screen.blit(background, background_rect)
    all_sprites1.draw(screen)
    gun.app(mouse_pos, screen)  
    for elem in targets: 
        if not elem.alive:
            targets.remove(elem)
##            pig_1 = Pig(10000, 10000, 20, 20, 0)
    for elem in bullets:#bul motion & checking alive
        bird = Bird(elem.x, elem.y, 40, 40, 0)
        bird_gr = pg.sprite.GroupSingle()
        bird_gr.add(bird)
        bird_gr.draw(screen)
        bird_gr.update()
        if elem.t > 0:
            elem.t -= 1
            elem.move(screen)
        elif elem.t == 0:
            elem.t = -1
            pg.sprite.Sprite.kill(bird)
        else:
            bullets.remove(elem)
##            bird=(10000, 10000, 20, 20, 0)
        for targett in targets: #hittest target & bul
            if Hit_test.target(targett, elem):
                targett.alive = False
                elem.t = 0
##                pg.sprite.bird.kill()
                count+=1
            if count == 1:
                pg.time.delay(2000)
                global game_mode1
                global main_menu_mode
                game_mode1 = False
                main_menu_mode = True
                count=0
        if Hit_test.wblock(elem, 800-30, 540-30, 60):
            elem.change_vel()
            elem.move(screen)
        if Hit_test.wblock(elem, 860-30, 540-30, 60):
            elem.change_vel()
            elem.move(screen)
        if Hit_test.wblock(elem, 740-30, 540-30, 60):
            elem.change_vel()
            elem.move(screen)
        if Hit_test.wblock(elem, 740-30, 480-30, 60):
            elem.change_vel()
            elem.move(screen)
        if Hit_test.wblock(elem, 860-30, 480-30, 60):
            elem.change_vel()
            elem.move(screen)
def level_2():
    targets = []
    targett1 = Target(800, 490, 20)
    targett2 = Target(538, 370, 30)
    targett3 = Target(812, 370, 30)
    targets.append(targett1)
    targets.append(targett2)
    targets.append(targett3)
    count = 0
    all_sprites2.update()
    screen.fill(BLACK)
    screen.blit(background, background_rect)
    all_sprites2.draw(screen)
    gun.app(mouse_pos, screen)  
    for elem in targets: 
        if not elem.alive:
            targets.remove(elem)
##            pg.sprite.Sprite.kill(pig)
    for elem in bullets:#bul motion & checking alive
        bird = Bird(elem.x, elem.y, 40, 40, 0)
        bird_gr = pg.sprite.GroupSingle()
        bird_gr.add(bird)
        bird_gr.draw(screen)
        bird_gr.update()
        if elem.t > 0:
            elem.t -= 1
            elem.move(screen)
        elif elem.t == 0:
            elem.t = -1
        else:
            bullets.remove(elem)
        for targett in targets: #hittest target & bul
            if Hit_test.target(targett, elem):
                targett.alive = False
                elem.t = 0
                count+=1
            if count == 3:
                pg.time.delay(2000)
                global game_mode2
                global main_menu_mode
                game_mode2 = False
                main_menu_mode = True
                count=0
        if Hit_test.wblock(elem, 538-37, 503-37, 75):
            elem.change_vel()
            elem.move(screen)
        if Hit_test.wblock(elem, 812-37, 503-37, 75):
            elem.change_vel()
            elem.move(screen)
        if Hit_test.wblock(elem, 538-37, 428-37, 75):
            elem.change_vel()
            elem.move(screen)
        if Hit_test.wblock(elem, 812-37, 428-37, 75):
            elem.change_vel()
            elem.move(screen)
        if Hit_test.wstick(elem, 538-70, 385-5, 140, 10):
            elem.change_vel()
            elem.move(screen)
        if Hit_test.wstick(elem, 812-70, 385-5, 140, 10):
            elem.change_vel()
            elem.move(screen)

def level_3():
    targets = []
    targett1 = Target(800, 500, 30)
    targett2 = Target(538, 500, 10)
    targett3 = Target(812, 500, 10)
    targets.append(targett1)
    targets.append(targett2)
    targets.append(targett3)
    count = 0
    all_sprites3.update()
    screen.fill(BLACK)
    screen.blit(background, background_rect)
    all_sprites3.draw(screen)
    gun.app(mouse_pos, screen)  
    for elem in targets: 
        if not elem.alive:
            targets.remove(elem)
##            pg.sprite.Sprite.kill(pig)
    for elem in bullets:#bul motion & checking alive
        bird = Bird(elem.x, elem.y, 40, 40, 0)
        bird_gr = pg.sprite.GroupSingle()
        bird_gr.add(bird)
        bird_gr.draw(screen)
        bird_gr.update()
        if elem.t > 0:
            elem.t -= 1
            elem.move(screen)
        elif elem.t == 0:
            elem.t = -1
        else:
            bullets.remove(elem)
        for targett in targets: #hittest target & bul
            if Hit_test.target(targett, elem):
                targett.alive = False
                elem.t = 0
                count+=1
            if count == 3:
                pg.time.delay(2000)
                global game_mode3
                global main_menu_mode
                game_mode3 = False
                main_menu_mode = True
                count=0
pg.init()

FPS = 60

pg.display.update()
clock = pg.time.Clock()

#defining additional constants
v = 1

freq = 60

#defining default modes
finished = False
main_menu_mode = True
settings_menu_mode = False
game_mode1 = False
game_mode2 = False
game_mode3 = False
levels_mode = False

#defining objects in the game
main_menu = MainMenu()
settings_menu = Settings()
levels_menu = Levels()
gun = Gun(size)
bullets = []

game_objects = [main_menu, settings_menu, levels_menu]
screen.fill(BACKGROUND)

while not finished:
    clock.tick(FPS)
    pg.display.update()
    mouse_pos = pg.mouse.get_pos()
    m1 = pg.mouse.get_pressed()[0]
    if game_mode1 or game_mode2 or game_mode3: #defining power of gun's shot
        if m1 == 1:
            if v != 40:
                v += 1
                gun.lc += 0.5
                gun.color[0] += 6
    for event in pg.event.get():
        if event.type == pg.QUIT:
            finished = True
        #checking if the gun shots
        if event.type == pg.MOUSEBUTTONUP and (game_mode1 or game_mode2 or game_mode3) and event.button==1:
            bullets.append(Bullet(gun, mouse_pos, v))
            new_bullet = Bullet(gun, mouse_pos, v)
            new_bird = Bird(new_bullet.x, new_bullet.y, 40, 40, 0)
            new_bird_gr = pg.sprite.GroupSingle()
            new_bird_gr.add(new_bird)
            new_bird_gr.draw(screen)
            new_bird_gr.update()
            v = 1
            gun.lc = 15
            gun.color[0] = 0
        if event.type == pg.MOUSEBUTTONDOWN: #checking buttons' pushes
            if buttons_activated(main_menu_mode):
                if event.button == 1 and main_menu.button_e_check(event, size):
                    finished = True
                if event.button == 1 and main_menu.button_s_check(event, size):
                    main_menu_mode = False
                    settings_menu_mode = True
                if event.button == 1 and main_menu.button_b_check(event, size):
                    levels_mode = True
                    main_menu_mode = False
            if buttons_activated(settings_menu_mode):
                if event.button == 1 and settings_menu.button_r_check(event, size):
                    settings_menu_mode = False
                    main_menu_mode = True
                if event.button == 1 and settings_menu.button_m_check(event, size):
                    pg.mixer.music.load("Black_metal.mp3")
                    pg.mixer.music.play(-1)
                if event.button == 3 and settings_menu.button_m_check(event, size):
                    pg.mixer.music.stop()
            if buttons_activated(levels_mode):
                if event.button == 1 and levels_menu.button_l1_check(event, size):
                    levels_mode = False
                    game_mode1 = True
                if event.button == 1 and levels_menu.button_l2_check(event, size):
                    levels_mode = False
                    game_mode2 = True
                if event.button == 1 and levels_menu.button_l3_check(event, size):
                    levels_mode = False
                    game_mode3 = True
                if event.button == 1 and levels_menu.button_r_check(event, size):
                    levels_mode = False
                    main_menu_mode = True
    if main_menu_mode:
        settings_menu.disappear(size, screen)
        main_menu.appear(size, screen)
    if levels_mode:
        main_menu.disappear(size, screen)
        levels_menu.appear(size, screen)
    if settings_menu_mode:
        main_menu.disappear(size, screen)
        settings_menu.appear(size, screen)
    if game_mode1: 
        main_menu.disappear(size, screen)
        level_1()
    if game_mode2:
        main_menu.disappear(size, screen)
        level_2()
    if game_mode3:
        main_menu.disappear(size, screen)
        level_3()
pg.quit()
