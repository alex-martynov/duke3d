/*
 * SDL_mixer compatibility shim.
 *
 * The Windows build links against SDL2_mixer_ext (SDL Mixer X), which is
 *  API-compatible with SDL2_mixer but also plays MIDI through the native
 *  Windows synthesizer. Old code includes "SDL_mixer.h"; route it here.
 */
#ifndef _INCL_COMPAT_SDL_MIXER_H_
#define _INCL_COMPAT_SDL_MIXER_H_

#include "SDL_mixer_ext.h"

#endif
