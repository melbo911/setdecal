
# setdecal

setdecal is a little program which scans the X-Plane "Custom Scenery" for 
"Ortho4XP" tiles and changes the decal definition inside the "terrain" files.

This allows you to change the surface structure so that they look more realistic. 

The default decal in Ortho4XP, which gets set during the creation process of
new tile, is "maquify_2_green_key.dcl".

My (and others) preference is the "grass_and_stony_dirt_1.dcl" decal and therefor
it is the default decal which gets installed when called with no parameter specified.

However, you can add the name of another decal on the command line, to apply this 
instead.

If called with option "-h" , it shows all valid decal names:

```
$ ./setdecal -h
setdecal - 0.1.0

usage: setdecal [decal]

default Ortho4XP decal: maquify_2_green_key.dcl
default setdecal decal: grass_and_stony_dirt_1.dcl
```


valid decals:

```
AGB_grass_and_asphalt_1.dcl
AGS_shrub_dirt_green_key_1.dcl
AGS_suburban_garden_1.dcl
AGS_suburban_garden_1_proj.dcl
AGS_suburban_garden_vdry_1.dcl
AGS_suburban_wet_1.dcl
AG_concrete.dcl
LF_grey_1_mid.dcl
apt_asphalt.dcl
apt_concrete.dcl
apt_concrete_tiles1.dcl
apt_grass.dcl
apt_markings1.dcl
apt_markings2.dcl
apt_markings3.dcl
apt_wood_planks1.dcl
asphalt_and_stony_dirt.dcl
asphalt_gravel_edge.dcl
bridges18.dcl
cracked_dirt_and_asphalt.dcl
cracked_dirt_and_asphalt2.dcl
dry_grass_and_stony_dirt_1.dcl
dry_grass_and_stony_dirt_2.dcl
flinty_dirt_1.dcl
flinty_dirt_2.dcl
flinty_dirt_3.dcl
grass_and_asphalt_1.dcl
grass_and_asphalt_2.dcl
grass_and_asphalt_3.dcl
grass_and_asphalt_green_key.dcl
grass_and_asphalt_green_key2.dcl
grass_and_shrubs.dcl
grass_and_stony_dirt_1.dcl
grass_and_stony_dirt_1_fine.dcl
grass_dirt_and_RGB_LF.dcl
grasses_combo.dcl
grasses_combo_2.dcl
grasses_combo_3.dcl
industrial_asphalt.dcl
industrial_outlay.dcl
long_grass_and_gravel_1.dcl
long_grass_and_shrubs.dcl
low_freq_mod_1.dcl
maquify_1_alpha_key.dcl
maquify_1_green_key.dcl
maquify_1_mod_key.dcl
maquify_2_green_key.dcl
mid_freq_test.dcl
park_grass_wet.dcl
rail_ballast_dry.dcl
rail_ballast_gray_dry.dcl
rail_dry_drp.dcl
rail_dry_grass_emb.dcl
rail_dry_grd.dcl
rail_trackbed_brown.dcl
road_EU_dry.dcl
road_EU_rural.dcl
road_hwy.dcl
road_res_dry.dcl
road_res_dry_grass_edge.dcl
road_res_dry_gravel_edge.dcl
road_res_junc_dry.dcl
shingle.dcl
shrub_and_dirt_1.dcl
shrub_and_dirt_2.dcl
shrubs_asphalt.dcl
stony_dirt_1.dcl
stony_dirt_2.dcl
test_decal.dcl
very_long_grass.dcl
very_long_grass_and_dirt.dcl
very_long_grass_modulator2.dcl

```
