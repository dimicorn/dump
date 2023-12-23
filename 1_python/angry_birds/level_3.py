from level_objects import *

all_sprites3 = pg.sprite.Group()
block_lvl3 = pg.sprite.Group()
pig_lvl3 = pg.sprite.Group()
bird_lvl3 = pg.sprite.Group()

pig_1_lvl3 = Pig(705, 480, 40, 40, 0)
all_sprites3.add(pig_1_lvl3)
pig_lvl3.add(pig_1_lvl3)
pig_1_lvl3_gr = pg.sprite.GroupSingle()
pig_1_lvl3_gr.add(pig_1_lvl3)

pig_2_lvl3 = Pig(765, 550, 40, 40, 0)
all_sprites3.add(pig_2_lvl3)
pig_lvl3.add(pig_2_lvl3)
pig_2_lvl3_gr = pg.sprite.GroupSingle()
pig_2_lvl3_gr.add(pig_2_lvl3)

pig_3_lvl3 = Pig(900, 550, 40, 40, 0)
all_sprites3.add(pig_3_lvl3)
pig_lvl3.add(pig_3_lvl3)
pig_3_lvl3_gr = pg.sprite.GroupSingle()
pig_3_lvl3_gr.add(pig_3_lvl3)

wood_block1_3 = Wood_block(635, 535, 70, 70, 0)
all_sprites3.add(wood_block1_3)                                                                 
block_lvl3.add(wood_block1_3)

wood_block2_3 = Wood_block(635, 465, 70, 70, 0)
all_sprites3.add(wood_block2_3)                                                                 
block_lvl3.add(wood_block2_3)

wood_block3_3 = Wood_block(635, 395, 70, 70, 0)
all_sprites3.add(wood_block3_3)                                                                 
block_lvl3.add(wood_block3_3)

wood_block4_3 = Wood_block(705, 535, 70, 70, 0)
all_sprites3.add(wood_block4_3)                                                                 
block_lvl3.add(wood_block4_3)

wood_block5_3 = Wood_block(815, 535, 40, 70, 0)
all_sprites3.add(wood_block5_3)                                                                 
block_lvl3.add(wood_block5_3)

wood_stick1_3 = Wood_stick(765, 495, 80, 10, 0)
all_sprites3.add(wood_stick1_3)                                                                 
block_lvl3.add(wood_stick1_3)



