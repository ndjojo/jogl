/**
 * Copyright 2019 JogAmp Community. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 * 
 *    1. Redistributions of source code must retain the above copyright notice, this list of
 *       conditions and the following disclaimer.
 * 
 *    2. Redistributions in binary form must reproduce the above copyright notice, this list
 *       of conditions and the following disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY JogAmp Community ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL JogAmp Community OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * The views and conclusions contained in the software and documentation are those of the
 * authors and should not be interpreted as representing official policies, either expressed
 * or implied, of JogAmp Community.
 */

#include "drm_gbm.h"

static jmethodID sizeChangedID = NULL;
static jmethodID positionChangedID = NULL;
static jmethodID visibleChangedID = NULL;
static jmethodID windowDestroyNotifyID = NULL;

/**
 * Display
 */

JNIEXPORT jboolean JNICALL Java_jogamp_newt_driver_egl_gbm_DisplayDriver_initIDs
  (JNIEnv *env, jclass clazz)
{
    DBG_PRINT( "EGL_GBM.Display initIDs ok\n" );
    return JNI_TRUE;
}

JNIEXPORT void JNICALL Java_jogamp_newt_driver_egl_gbm_DisplayDriver_DispatchMessages0
  (JNIEnv *env, jclass clazz)
{
}

/**
 * Screen
 */
JNIEXPORT jboolean JNICALL Java_jogamp_newt_driver_egl_gbm_ScreenDriver_initIDs
  (JNIEnv *env, jclass clazz)
{
    DBG_PRINT( "EGL_GBM.Screen initIDs ok\n" );
    return JNI_TRUE;
}

/**
 * Window
 */

JNIEXPORT jboolean JNICALL Java_jogamp_newt_driver_egl_gbm_WindowDriver_initIDs
  (JNIEnv *env, jclass clazz)
{
    sizeChangedID = (*env)->GetMethodID(env, clazz, "sizeChanged", "(ZIIZ)V");
    positionChangedID = (*env)->GetMethodID(env, clazz, "positionChanged", "(ZII)V");
    visibleChangedID = (*env)->GetMethodID(env, clazz, "visibleChanged", "(Z)V");
    windowDestroyNotifyID = (*env)->GetMethodID(env, clazz, "windowDestroyNotify", "(Z)Z");
    if (sizeChangedID == NULL ||
        positionChangedID == NULL ||
        visibleChangedID == NULL ||
        windowDestroyNotifyID == NULL) {
        DBG_PRINT( "initIDs failed\n" );
        return JNI_FALSE;
    }
    DBG_PRINT( "EGL_GBM.Window initIDs ok\n" );
    return JNI_TRUE;
}

