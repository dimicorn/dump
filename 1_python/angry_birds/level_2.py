from level_objects import *



all_sprites2 = pg.sprite.Group()
block_lvl2 = pg.sprite.Group()
pig_lvl2 = pg.sprite.Group()
bird_lvl2 = pg.sprite.Group()

wood_stick1_2 = Wood_stick(525, 555, 50, 30, 0)
all_sprites2.add(wood_stick1_2)                                                                 
block_lvl2.add(wood_stick1_2)

wood_stick2_2 = Wood_stick(575, 555, 50, 30, 0)
all_sprites2.add(wood_stick2_2)                                                                 
block_lvl2.add(wood_stick2_2)

wood_stick3_2 = Wood_stick(775, 555, 50, 30, 0)
all_sprites2.add(wood_stick3_2)                                                                 
block_lvl2.add(wood_stick3_2)

wood_stick4_2 = Wood_stick(825, 555, 50, 30, 0)
all_sprites2.add(wood_stick4_2)                                                                 
block_lvl2.add(wood_stick4_2)

wood_stick5_2 = Wood_stick(675, 535, 200, 10, 0)
all_sprites2.add(wood_stick5_2)                                                                 
block_lvl2.add(wood_stick5_2)

pig_1_2 = Pig(675, 500, 60, 60, 0)
all_sprites2.add(pig_1_2)
pig_lvl2.add(pig_1_2)
pig_1_2_gr = pg.sprite.GroupSingle()
pig_1_2_gr.add(pig_1_2)

wood_block1_2 = Wood_block(538, 503, 75, 75, 0)
all_sprites2.add(wood_block1_2)                                                                 
block_lvl2.add(wood_block1_2)

wood_block2_2 = Wood_block(812, 503, 75, 75, 0)
all_sprites2.add(wood_block2_2)                                                                 
block_lvl2.add(wood_block2_2)

wood_block3_2 = Wood_block(538, 428, 75, 75, 0)
all_sprites2.add(wood_block3_2)                                                                 
block_lvl2.add(wood_block3_2)

wood_block4_2 = Wood_block(812, 428, 75, 75, 0)
all_sprites2.add(wood_block4_2)                                                                 
block_lvl2.add(wood_block4_2)

wood_stick6_2 = Wood_stick(538, 385, 140, 10, 0)
all_sprites2.add(wood_stick6_2)                                                                 
block_lvl2.add(wood_stick6_2)

wood_stick7_2 = Wood_stick(812, 385, 140, 10, 0)
all_sprites2.add(wood_stick7_2)                                                                 
block_lvl2.add(wood_stick7_2)

pig_2_2 = Pig(538, 365, 30, 30, 0)
all_sprites2.add(pig_2_2)
pig.add(pig_2_2)
pig_2_2_gr = pg.sprite.GroupSingle()
pig_2_2_gr.add(pig_2_2)

pig_3_2 = Pig(812, 365, 30, 30, 0)
all_sprites2.add(pig_3_2)
pig.add(pig_3_2)
pig_3_2_gr = pg.sprite.GroupSingle()
pig_3_2_gr.add(pig_3_2)








