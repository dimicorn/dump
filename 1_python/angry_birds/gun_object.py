from gun_colors import *
import random as rnd
import math as m
import pygame.draw as pgd
from level_1 import *


class Gun:
    def __init__(self, size):
        self.x = 50
        self.y = 550
        self.l = 21
        self.w = 10
        self.lc = 15
        self.wc = 4
        self.color = list(GUN_COLOR)

    def app(self, pos, screen):
        if (self.y-pos[1]) <= 0:
            arctg = 0
            x2 = self.x
            y2 = self.y - int(self.lc)
        else:
            arctg = m.atan((pos[0]-self.x)/(self.y-pos[1]))
            x2 = int(self.x + self.lc*m.sin(arctg))
            y2 = int(self.y - self.lc*m.cos(arctg))
        pgd.rect(screen, GUN_COLOR, [(self.x-self.l, self.y-self.w//2), (int(2*self.l), self.w)])
        pgd.rect(screen, GUN_COLOR, [(self.x-self.l, self.y-self.w//2-self.w), (3, self.w)])
        pgd.line(screen, self.color, (self.x, self.y-self.w//2), (x2, y2), self.wc)
        
    def disapp(self, pos, screen):
        pgd.rect(screen, BACKGROUND, [(self.x-35, self.y-35), (70, 40)])
        
        
      
class Target:
    def __init__(self, x, y, r):
        self.x = x
        self.y = y
        self.r = r
        self.alive = True
    
class Bullet:
    def __init__(self, gun, pos, v):
        if (gun.y-pos[1]) <= 0:
            arctg = 0
            self.x = gun.x
            self.y = gun.y - gun.l
        else:
            arctg = m.atan((pos[0]-gun.x)/(gun.y-pos[1]))
            self.x = int(gun.x + gun.l*m.sin(arctg))
            self.y = int(gun.y - gun.l*m.cos(arctg))
        self.v = v
        self.vx = -int(self.v*m.sin(arctg))
        self.vy = int(self.v*m.cos(arctg))
        self.t = 200
        self.r = 20
        self.active = False
        
    def change_coor(self):
        self.x -= self.vx
        self.y -= self.vy
        self.vy -= 1
        if self.y >= 550:
            self.vy = (-self.vy*0.8)
            self.y -= self.vy
        
    def move(self, screen):
        self.change_coor()
        
    def change_vel(self):
        self.vy = int(-self.vy*0.8)
        self.vx = int(-self.vx*0.8)
class Hit_test:
    
    def target (targett, bullett):
        s = m.sqrt((bullett.x-targett.x)**2+(bullett.y-targett.y)**2)
        if s < (bullett.r + targett.r):
            return True
        else:
            return False
        
    def wblock (bullett, blockx, blocky, a):
        if blockx <= bullett.x <= blockx+a and blocky <= bullett.y <= blocky+a:
            return True
        else:
            return False
        
    def wstick (bullett, stickx, sticky, w, h):
        if stickx <= bullett.x <= stickx + w and sticky <= bullett.y <= sticky + h:
            return True
        else:
            return False
        
