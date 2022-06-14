/*
 * Copyright 2015 Your Name <your@email.address>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#ifndef SOLITAREVIEW_H
#define SOLITAREVIEW_H


#include <SupportDefs.h>

#include <Bitmap.h>
#include <Resources.h>
#include <View.h>
#include <MenuItem.h>
#include <Rect.h>

#include <SimpleGameSound.h>

#include "Solitare.h"

#define OPTION_MESSAGE_TYPE 'OPTI'
extern const char* OPTION_MESSAGE_LABEL;

const uint32 sToggleSoundMessage = 'TSnd';

BMessage* NewSolitareOptionMessage(uint32 what);

class SolitareView: public BView {
public:
	SolitareView(BRect frame, const char *name, uint32 resizingMode, uint32 flags);
	
	virtual ~SolitareView();
	virtual void NewGame();
	virtual BMenu* GetOptionMenu();
	virtual void Resize(float newWidth, float newHeight);
	virtual void ReceiveOptionMessage(BMessage* message);
	virtual void Hint();
	
protected:
	int windowWidth;
	int windowHeight;
	
	BBitmap*			fCards[CARDS_IN_DECK];
	BBitmap*			fBack[CACHED_BACKS];

	BBitmap*			fEmpty;
	BSimpleGameSound* 	fShuffle;
	BSimpleGameSound* 	fFanfare;
	
	BResources*			fResources;
	
	bool				fSoundEnabled;
	BMenuItem*			fToggleSoundItem;
	
	void				_LoadBitmaps();
	BSimpleGameSound*	_LoadSound(const char* resourceName);
	
	virtual	void		AllAttached();
	virtual void		_GenerateBoard();
	
private:
};


#endif // SOLITAREVIEW_H
