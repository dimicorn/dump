from level_objects import *

all_sprites1 = pg.sprite.Group()
block_lvl1 = pg.sprite.Group()
pig_lvl1 = pg.sprite.Group()
bird_lvl1 = pg.sprite.Group()

wood_block1 = Wood_block(800, 540, 60, 60, 0)
all_sprites1.add(wood_block1)                                                          
block_lvl1.add(wood_block1)

wood_block2 = Wood_block(860, 540, 60, 60, 0)
all_sprites1.add(wood_block2)
block_lvl1.add(wood_block2)

wood_block3 = Wood_block(740, 540, 60, 60, 0)
all_sprites1.add(wood_block3)                                                                 
block_lvl1.add(wood_block3)

wood_block4 = Wood_block(740, 480, 60, 60, 0)
all_sprites1.add(wood_block4)
block_lvl1.add(wood_block4)

wood_block5 = Wood_block(860, 480, 60, 60, 0)
all_sprites1.add(wood_block5)                                                                 
block_lvl1.add(wood_block5)





