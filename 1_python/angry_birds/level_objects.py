import pygame as pg
import numpy as np
import random
from pygame.draw import *
from random import randint
from colors import *

def surface(size):
    return pg.display.set_mode(size)

WIDTH = 1000
HEIGHT = 600
size =(WIDTH, HEIGHT)

X1, Y1, W, H, X2, Y2, R = [], [], [], [], [], [], []    

class Draw(pg.sprite.Sprite):
    def __init__ (self, picture, pos_x, pos_y, width, height, speed_angle):
        pg.sprite.Sprite.__init__(self)
        file = pg.image.load(picture)
        self.image_orig = file
        self.image_orig.set_colorkey(CYAN)
        self.image = self.image_orig.copy()
        self.image_orig = pg.transform.scale(file, (width, height))
        self.rect = self.image.get_rect()
        self.rect.centerx = pos_x  
        self.rect.centery = pos_y
        self.rot = 0
        self.rot_speed = speed_angle
        self.last_update = pg.time.get_ticks()

    def rotate(self):
        self.rot = (self.rot + self.rot_speed) % 360
        new_image = pg.transform.rotate(self.image_orig, self.rot)
        old_center = self.rect.center
        self.image = new_image
        self.rect = self.image.get_rect()
        self.rect.center = old_center

    def update(self):
        now = pg.time.get_ticks()
        if now - self.last_update > 50:
            self.last_update = now
            self.rotate()        
        
class Wood_block(Draw):
    
    def __init__ (self, pos_x, pos_y, width, height, speed_angle):
        picture = "wood_block_CYAN.png"
        super().__init__(picture ,pos_x, pos_y, width, height, speed_angle)
        x, y = pos_x-width/2, pos_y-height/2
        X1.append(x)
        Y1.append(y)
        W.append(width)
        H.append(height)

    def rotate(self):
        super().rotate()

    def update(self):
        super().update()

class Wood_stick(Draw):
    
    def __init__ (self, pos_x, pos_y, width, height, speed_angle):
        picture = "wood_stick_CYAN.png"
        super().__init__(picture ,pos_x, pos_y, width, height, speed_angle)
        x, y = pos_x-width/2, pos_y-height/2
        X1.append(x)
        Y1.append(y)
        W.append(width)
        H.append(height)

    def rotate(self):
        super().rotate()

    def update(self):
        super().update()

class Pig(Draw):
    
    def __init__ (self, pos_x, pos_y, width, height, speed_angle):
        picture = "pig_ordinary_CYAN.png"
        super().__init__(picture ,pos_x, pos_y, width, height, speed_angle)
        r = 0.75*((width/2)**2+(height/2)**2)**0.5
##        pg.draw.circle(screen, RED, (pos_x, pos_y), r)
        X2.append(pos_x)
        Y2.append(pos_y)
        R.append(r)

    def rotate(self):
        super().rotate()

    def update(self):
        super().update()


class Bird(Draw):
    
    def __init__ (self, pos_x, pos_y, width, height, speed_angle):
        picture = "bird_red_CYAN.png"
        super().__init__(picture ,pos_x, pos_y, width, height, speed_angle)
        r = 0.75*((width/2)**2+(height/2)**2)**0.5
        X2.append(pos_x)
        Y2.append(pos_y)
        R.append(r)

    def rotate(self):
        super().rotate()

    def update(self):
        super().update()

screen = surface(size)

background = pg.image.load("background1.jpg")
background_rect = background.get_rect()

pg.init()

all_sprites = pg.sprite.Group()
block = pg.sprite.Group()
pig = pg.sprite.Group()
bird = pg.sprite.Group()

