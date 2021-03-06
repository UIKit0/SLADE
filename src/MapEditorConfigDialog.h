
#ifndef __MAP_EDITOR_CONFIG_DIALOG_H__
#define __MAP_EDITOR_CONFIG_DIALOG_H__

#include "SDialog.h"
#include "Archive.h"
#include "ListView.h"

class MapPreviewCanvas;
class BaseResourceChooser;
class ResourceArchiveChooser;
class wxImageList;
class MapEditorConfigDialog : public SDialog
{
private:
	wxChoice*					choice_game_config;
	wxChoice*					choice_port_config;
	BaseResourceChooser*		choice_base_resource;
	ListView*					list_maps;
	ResourceArchiveChooser*		rac_resources;
	wxButton*					btn_new_map;
	MapPreviewCanvas*			canvas_preview;
	wxImageList*				img_list;
	wxButton*					btn_ok;
	wxButton*					btn_cancel;
	string						game_current;
	string						port_current;
	int							map_format;
	bool						creating;

	Archive*					archive;
	vector<Archive::mapdesc_t>	maps;
	vector<int>					ports_list;

public:
	MapEditorConfigDialog(wxWindow* parent, Archive* archive = NULL, bool show_maps = true, bool creating = false);
	~MapEditorConfigDialog();

	void				populateGameList();
	void				populatePortList();
	void				populateMapList();
	Archive::mapdesc_t	selectedMap();
	bool				configMatchesMap(Archive::mapdesc_t map);
	string				selectedGame();
	string				selectedPort();

	// Events
	void	onChoiceGameConfigChanged(wxCommandEvent& e);
	void	onChoicePortConfigChanged(wxCommandEvent& e);
	void	onMapActivated(wxListEvent& e);
	void	onBtnNewMap(wxCommandEvent& e);
	void	onMapSelected(wxListEvent& e);
	void	onBtnOK(wxCommandEvent& e);
	void	onBtnCancel(wxCommandEvent& e);
};

#endif//__MAP_EDITOR_CONFIG_DIALOG_H__
