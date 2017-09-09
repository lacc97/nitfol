/*  Nitfol - z-machine interpreter using Glk for output.
    Copyright (C) 1999  Evin Robertson

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.

    The author can be reached at nitfol@deja.com
*/
#include "nitfol.h"

#include "gi_blorb.h"


static void set_zfile(strid_t file)
{
  glk_stream_set_position(file, 0, seekmode_End);
  total_size = glk_stream_get_position(file);
  glk_stream_set_position(file, 0, seekmode_Start);

  current_zfile = file;
  zfile_offset = 0;

  if(!load_header(file, total_size, FALSE)) {
    /* FIMXE: add code to check to see if it's a jzexe product, and perhaps
       even code to grab it out of disk images */
    current_zfile = NULL;
    return;
  }
  
  glk_stream_set_position(file, zfile_offset, seekmode_Start);
}


static strid_t savefile;

int game_use_file(strid_t file)
{
  giblorb_map_t *map;
  giblorb_result_t res;
  strid_t z;
  if(wrap_gib_create_map(file, &map) == giblorb_err_None) {
    if(!current_zfile) {
      if(wrap_gib_load_resource(map, giblorb_method_FilePos, &res,
		giblorb_ID_Exec, 0) == giblorb_err_None) {
	current_zfile = file;
	zfile_offset = res.data.startpos;
	total_size = res.length;
      }
    }
    if(!blorb_file)
      wrap_gib_count_resources(map, giblorb_ID_Pict, &imagecount, NULL, NULL);
    wrap_gib_destroy_map(map);

    if(!blorb_file) {
      if(wrap_gib_set_resource_map(file) == giblorb_err_None) {
	blorb_file = file;
	return TRUE;
      }
    }
  }

  if((z = quetzal_findgamefile(file)) != 0) {
    savefile = file;
    file = z;
  }

  if(!current_zfile) {
    set_zfile(file);

    return TRUE;
  }

  return FALSE;
}


void glk_main(void)
{
  if(!current_zfile) {
    winid_t tempwin;
    tempwin = glk_window_open(0, 0, 100, wintype_TextBuffer, 0);
    while(!current_zfile) {
      strid_t z = n_file_prompt(fileusage_Data | fileusage_BinaryMode,
				filemode_Read);
      if(!z) {
	w_glk_put_string_stream(glk_window_get_stream(tempwin),
				"File not found.");
	continue;
      }
      set_zfile(z);
    }
    glk_window_close(tempwin, NULL);
  }
  z_init(current_zfile);
  if(savefile) {
    if(restorequetzal(savefile)) {
      if(zversion <= 3)
	mop_take_branch();
      else
	mop_store_result(2);
    }
  }
  init_undo();
  decode();
}
