
/*******************************************************************
 * SLADE - It's a Doom Editor
 * Copyright (C) 2008-2014 Simon Judd
 *
 * Email:       sirjuddington@gmail.com
 * Web:         http://slade.mancubus.net
 * Filename:    MapDisplayPrefsPanel.cpp
 * Description: Panel containing preference controls for the map
 *              editor
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *******************************************************************/


/*******************************************************************
 * INCLUDES
 *******************************************************************/
#include "Main.h"
#include "WxStuff.h"
#include "MapEditorPrefsPanel.h"


/*******************************************************************
 * EXTERNAL VARIABLES
 *******************************************************************/
EXTERN_CVAR(Bool, scroll_smooth)
EXTERN_CVAR(Bool, selection_clear_click)
EXTERN_CVAR(Bool, map_merge_undo_step)
EXTERN_CVAR(Bool, mobj_props_auto_apply)
EXTERN_CVAR(Bool, map_remove_invalid_lines)


/*******************************************************************
 * MAPEDITORPREFSPANEL CLASS FUNCTIONS
 *******************************************************************/

/* MapEditorPrefsPanel::MapEditorPrefsPanel
 * MapEditorPrefsPanel class constructor
 *******************************************************************/
MapEditorPrefsPanel::MapEditorPrefsPanel(wxWindow* parent) : PrefsPanelBase(parent)
{
	// Create sizer
	wxBoxSizer* psizer = new wxBoxSizer(wxVERTICAL);
	SetSizer(psizer);

	// Create frame+sizer
	wxStaticBox* frame = new wxStaticBox(this, -1, "Map Editor Preferences");
	wxStaticBoxSizer* sizer = new wxStaticBoxSizer(frame, wxVERTICAL);
	psizer->Add(sizer, 1, wxEXPAND|wxALL, 4);

	// Smooth scroll
	cb_scroll_smooth = new wxCheckBox(this, -1, "Enable smooth scrolling");
	sizer->Add(cb_scroll_smooth, 0, wxEXPAND|wxALL, 4);

	// Clear selection on click
	cb_selection_clear_click = new wxCheckBox(this, -1, "Clear selection when nothing is clicked");
	sizer->Add(cb_selection_clear_click, 0, wxEXPAND|wxLEFT|wxRIGHT|wxBOTTOM, 4);

	// Merge undo step
	cb_merge_undo_step = new wxCheckBox(this, -1, "Create a 'Merge' undo level on move/edit map architecture");
	sizer->Add(cb_merge_undo_step, 0, wxEXPAND|wxLEFT|wxRIGHT|wxBOTTOM, 4);

	// Auto apply property changes
	cb_props_auto_apply = new wxCheckBox(this, -1, "Automatically apply property panel changes");
	sizer->Add(cb_props_auto_apply, 0, wxEXPAND|wxLEFT|wxRIGHT|wxBOTTOM, 4);

	// Auto remove invalid lines
	cb_remove_invalid_lines = new wxCheckBox(this, -1, "Remove any resulting invalid lines on sector delete");
	sizer->Add(cb_remove_invalid_lines, 0, wxEXPAND|wxLEFT|wxRIGHT|wxBOTTOM, 4);

	Layout();
}

/* MapEditorPrefsPanel::~MapEditorPrefsPanel
 * MapEditorPrefsPanel class destructor
 *******************************************************************/
MapEditorPrefsPanel::~MapEditorPrefsPanel()
{
}

/* MapEditorPrefsPanel::init
 * Initialises panel controls
 *******************************************************************/
void MapEditorPrefsPanel::init()
{
	cb_scroll_smooth->SetValue(scroll_smooth);
	cb_selection_clear_click->SetValue(selection_clear_click);
	cb_merge_undo_step->SetValue(map_merge_undo_step);
	cb_props_auto_apply->SetValue(mobj_props_auto_apply);
	cb_remove_invalid_lines->SetValue(map_remove_invalid_lines);
}

/* MapEditorPrefsPanel::applyPreferences
 * Applies preference values from the controls to CVARs
 *******************************************************************/
void MapEditorPrefsPanel::applyPreferences()
{
	scroll_smooth = cb_scroll_smooth->GetValue();
	selection_clear_click = cb_selection_clear_click->GetValue();
	map_merge_undo_step = cb_merge_undo_step->GetValue();
	mobj_props_auto_apply = cb_props_auto_apply->GetValue();
	map_remove_invalid_lines = cb_remove_invalid_lines->GetValue();
}
