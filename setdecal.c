/*
#
# melbo @ https://x-plane.org
#
*/

#define VERSION "0.1.0"

#ifdef _WIN32
 #include <windows.h>
 #include <process.h>
 #include "dirent.h"
#else
 #include <libgen.h>
 #include <unistd.h>
 #include <dirent.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define MAX_TXT 1024

#define XSCENERYDIR "./Custom Scenery"         /* where to look for orthos */

#define DEF_DECAL "grass_and_stony_dirt_1.dcl" /* default Orthoo4XP decal */
#define ORG_DECAL "maquify_2_green_key.dcl"    /* default setdecal decal */

char decal[MAX_TXT];

/*-----------------------------------------------------------------*/

void printDecals() {
   printf("valid decals: \n\n"
      "  AGB_grass_and_asphalt_1.dcl\n"
      "  AGS_shrub_dirt_green_key_1.dcl\n"
      "  AGS_suburban_garden_1.dcl\n"
      "  AGS_suburban_garden_1_proj.dcl\n"
      "  AGS_suburban_garden_vdry_1.dcl\n"
      "  AGS_suburban_wet_1.dcl\n"
      "  AG_concrete.dcl\n"
      "  LF_grey_1_mid.dcl\n"
      "  apt_asphalt.dcl\n"
      "  apt_concrete.dcl\n"
      "  apt_concrete_tiles1.dcl\n"
      "  apt_grass.dcl\n"
      "  apt_markings1.dcl\n"
      "  apt_markings2.dcl\n"
      "  apt_markings3.dcl\n"
      "  apt_wood_planks1.dcl\n"
      "  asphalt_and_stony_dirt.dcl\n"
      "  asphalt_gravel_edge.dcl\n"
      "  bridges18.dcl\n"
      "  cracked_dirt_and_asphalt.dcl\n"
      "  cracked_dirt_and_asphalt2.dcl\n"
      "  dry_grass_and_stony_dirt_1.dcl\n"
      "  dry_grass_and_stony_dirt_2.dcl\n"
      "  flinty_dirt_1.dcl\n"
      "  flinty_dirt_2.dcl\n"
      "  flinty_dirt_3.dcl\n"
      "  grass_and_asphalt_1.dcl\n"
      "  grass_and_asphalt_2.dcl\n"
      "  grass_and_asphalt_3.dcl\n"
      "  grass_and_asphalt_green_key.dcl\n"
      "  grass_and_asphalt_green_key2.dcl\n"
      "  grass_and_shrubs.dcl\n"
      "  grass_and_stony_dirt_1.dcl\n"
      "  grass_and_stony_dirt_1_fine.dcl\n"
      "  grass_dirt_and_RGB_LF.dcl\n"
      "  grasses_combo.dcl\n"
      "  grasses_combo_2.dcl\n"
      "  grasses_combo_3.dcl\n"
      "  industrial_asphalt.dcl\n"
      "  industrial_outlay.dcl\n"
      "  long_grass_and_gravel_1.dcl\n"
      "  long_grass_and_shrubs.dcl\n"
      "  low_freq_mod_1.dcl\n"
      "  maquify_1_alpha_key.dcl\n"
      "  maquify_1_green_key.dcl\n"
      "  maquify_1_mod_key.dcl\n"
      "  maquify_2_green_key.dcl\n"
      "  mid_freq_test.dcl\n"
      "  park_grass_wet.dcl\n"
      "  rail_ballast_dry.dcl\n"
      "  rail_ballast_gray_dry.dcl\n"
      "  rail_dry_drp.dcl\n"
      "  rail_dry_grass_emb.dcl\n"
      "  rail_dry_grd.dcl\n"
      "  rail_trackbed_brown.dcl\n"
      "  road_EU_dry.dcl\n"
      "  road_EU_rural.dcl\n"
      "  road_hwy.dcl\n"
      "  road_res_dry.dcl\n"
      "  road_res_dry_grass_edge.dcl\n"
      "  road_res_dry_gravel_edge.dcl\n"
      "  road_res_junc_dry.dcl\n"
      "  shingle.dcl\n"
      "  shrub_and_dirt_1.dcl\n"
      "  shrub_and_dirt_2.dcl\n"
      "  shrubs_asphalt.dcl\n"
      "  stony_dirt_1.dcl\n"
      "  stony_dirt_2.dcl\n"
      "  test_decal.dcl\n"
      "  very_long_grass.dcl\n"
      "  very_long_grass_and_dirt.dcl\n"
      "  very_long_grass_modulator2.dcl\n"
      );
}

/*-----------------------------------------------------------------*/

int scanOrthos() {
   FILE *in,*out;
   DIR *d, *t;
   struct dirent *dir;
   struct dirent *ter;

   char buf[MAX_TXT];
   char ortho[MAX_TXT];
   char terrain[MAX_TXT];
   char outfile[MAX_TXT];

   d = opendir(XSCENERYDIR);
   if (d) {
      printf("scanning %s\n",XSCENERYDIR);
      while ((dir = readdir(d)) != NULL) {
         if( strstr(dir->d_name,"zOrtho4XP_") ) {
            printf("doing %s\n",dir->d_name);
            strcpy(ortho,XSCENERYDIR);
            strcat(ortho,"/");
            strcat(ortho,dir->d_name);
            strcat(ortho,"/terrain");
            t = opendir(ortho);
            if (t) {
               while ((ter = readdir(t)) != NULL) {
                  if(  strstr(ter->d_name,".ter") && \
                     ! strstr(ter->d_name,"sea_overlay") ) {
                     strcpy(terrain,ortho);
                     strcat(terrain,"/");
                     strcat(terrain,ter->d_name);
/*
                     printf("doing %s\n",terrain);
*/
                     if ( (in = fopen(terrain,"r")) ) {
                        strcpy(outfile,terrain);
                        strcat(outfile,".tmp");
                        if ( (out = fopen(outfile,"w")) ) {
                           while ( fgets(buf, MAX_TXT, in) != NULL ) {
                              if ( strstr(buf,"DECAL_LIB") ) {
                                 sprintf(buf,"DECAL_LIB lib/g10/decals/%s\n",decal);
                              }
                              fputs(buf,out);
                           }
                           fclose(out);
                        }
                        fclose(in);
#ifdef _WIN32
                        remove(terrain);
#endif
                        if ( rename(outfile,terrain) ) {
                           printf("ERR: cannot rename %s\n",outfile);
                        }
                     } else {
                        printf("cannot open %s\n",terrain);
                     } 
                  }
               }
            }
            closedir(t);
         }
      }
      closedir(d);
   }
   return(1);
}

/*-----------------------------------------------------------------*/

void showHelp() {

    printf("\nusage: setdecal [decal]\n\n"
           "   default Ortho4XP decal: "ORG_DECAL"\n"
           "   default setdecal decal: "DEF_DECAL"\n\n"); 
    printDecals();
}

/*-----------------------------------------------------------------*/

int main(int argc, char **argv) {

   char tmp[256];

   printf("setdecal - %s\n",VERSION);

   if ( argc > 1 ) {
      if ( ! strcmp(argv[1],"-h") ) {
         showHelp();
         return(0);
      }
      strcpy(decal,argv[1]);
   } else {
      strcpy(decal,DEF_DECAL);
   }

#ifndef _WIN32
   strcpy(tmp,dirname(argv[0]));
   printf("changing to %s\n",tmp);
   chdir(tmp);
#endif

   printf ("setting decals to %s ...\n",decal);

   scanOrthos();
}

/*-----------------------------------------------------------------*/

