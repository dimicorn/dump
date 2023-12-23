from gun_colors import *
from button import*
import pygame.draw as pgd

class MainMenu:
    def __init__(self):
        self.x = 0
        self.y = 0
        self.theme = 0
        
    def appear(self, size, screen):
        pgd.rect(screen, MENU_COLOR[self.theme], [(self.x, self.y), (size[0], size[1])])
        start_button = Button(screen, 150, 100, 150, 60,[AQUA, BLACK] , 'StArT', 0, 'Times', 0, [1,1,1,1])
        quit_button = Button(screen, 150, 180, 150, 60,[RED, BLACK] , 'QuIt', 0, 'Times', 0, [1,1,1,1])
        settings_button = Button(screen, 125, 260, 200, 60,[YELLOW, BLACK] , 'SeTtInGs', 0, 'Times', 0, [1,1,1,1])
        start_button.show(MENU_COLOR[self.theme])
        quit_button.show(MENU_COLOR[self.theme])
        settings_button.show(MENU_COLOR[self.theme])
        
    def disappear(self, size, screen):
        pgd.rect(screen, BACKGROUND, [(self.x, self.y), (size[0], size[1])])
    
    def button_b_check(self, event, size):
        pos_x = event.pos[0]
        pos_y = event.pos[1]
        if 300 > pos_x > 150 and  160 > pos_y > 100:
            return True
        else:
            return False
        
    def button_e_check(self, event, size):
        pos_x = event.pos[0]
        pos_y = event.pos[1]
        if 300 > pos_x > 150 and  240 > pos_y > 180:
            return True
        else:
            return False
        
    def button_s_check(self, event, size):
        pos_x = event.pos[0]
        pos_y = event.pos[1]
        if 325 > pos_x > 125 and  320 > pos_y > 260:
            return True
        else:
            return False                   


class Settings:
    
    def __init__(self):
        self.x = 0
        self.y = 0
        self.theme = 0
    
    def appear(self, size, screen):
        pgd.rect(screen, MENU_COLOR[self.theme], [(self.x, self.y), (size[0], size[1])])
        return_button = Button(screen, 150, 100, 180, 60,[GREEN, BLACK] , 'ReTuRn', 0, 'Times', 0, [1,1,1,1])
        music_button = Button(screen, 150, 170, 180, 60,[ORANGE, BLACK] , 'MuSiC', 0, 'Times', 0, [1,1,1,1])
        return_button.show(MENU_COLOR[self.theme])
        music_button.show(MENU_COLOR[self.theme])
        
    def disappear(self, size, screen):
         pgd.rect(screen, BACKGROUND, [(size[0], self.y), (self.x, size[1])])
         
    def button_r_check(self, event, size):
        pos_x = event.pos[0]
        pos_y = event.pos[1]
        if 330 > pos_x > 150 and  160 > pos_y > 100:
            return True
        else:
            return False
    
    def button_m_check(self, event, size):
        pos_x = event.pos[0]
        pos_y = event.pos[1]
        if 330 > pos_x > 150 and  230 > pos_y > 170:
            return True
        else:
            return False
        
class Levels():

    def __init__(self):
        self.x = 0
        self.y = 0
        self.theme = 0

    def appear (self, size, screen):
        pgd.rect(screen, MENU_COLOR[self.theme], [(self.x, self.y), (size[0], size[1])])
        level1_button = Button(screen, 250, 100, 180, 60,[YELLOW, BLACK] , 'LeVeL 1', 0, 'Times', 0, [1,1,1,1])
        level2_button = Button(screen, 250, 170, 180, 60,[RED, BLACK] , 'LeVeL 2', 0, 'Times', 0, [1,1,1,1])
        level3_button = Button(screen, 250, 250, 180, 60,[GREEN, BLACK] , 'LeVeL 3', 0, 'Times', 0, [1,1,1,1])
        return_button = Button(screen, 250, 320, 180, 60,[BLUE, BLACK] , 'ReTuRn', 0, 'Times', 0, [1,1,1,1])
        return_button.show(MENU_COLOR[self.theme])
        level1_button.show(MENU_COLOR[self.theme])
        level2_button.show(MENU_COLOR[self.theme])
        level3_button.show(MENU_COLOR[self.theme])

    def disappear(self, size, screen):
         pgd.rect(screen, BACKGROUND, [(size[0], self.y), (self.x, size[1])])

    def button_l1_check(self, event, size):
        pos_x = event.pos[0]
        pos_y = event.pos[1]
        if 430 > pos_x > 250 and  160 > pos_y > 100:
            return True
        else:
            return False
        
    def button_l2_check(self, event, size):
        pos_x = event.pos[0]
        pos_y = event.pos[1]
        if 430 > pos_x > 250 and  240 > pos_y > 170:
            return True
        else:
            return False
        
    def button_l3_check(self, event, size):
        pos_x = event.pos[0]
        pos_y = event.pos[1]
        if 430 > pos_x > 250 and  310 > pos_y > 250:
            return True
        else:
            return False

    def button_r_check(self, event, size):
        pos_x = event.pos[0]
        pos_y = event.pos[1]
        if 430 > pos_x > 250 and  380 > pos_y > 320:
            return True
        else:
            return False
        
