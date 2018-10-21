QPoisson
===============

[![license](https://img.shields.io/github/license/zigzagbob/QPoisson.svg)](https://github.com/zigzagbob/QPoisson/blob/master/LICENSE)
[![AppVeyor](https://img.shields.io/appveyor/ci/zigzagbob/QPoisson.svg)](https://ci.appveyor.com/project/zigzagbob/QPoisson)
[![Github All Releases](https://img.shields.io/github/downloads/zigzagbob/QPoisson/total.svg)](https://github.com/zigzagbob/QPoisson/releases)
[![GitHub release](https://img.shields.io/github/release/zigzagbob/QPoisson.svg)](https://github.com/zigzagbob/QPoisson/releases/latest)

Poisson Blending in Qt Frame

![LE interface](https://github.com/zigzagbob/zigzagbob.github.io/raw/master/RmPNG/qps.PNG)
![LE interface](https://github.com/zigzagbob/zigzagbob.github.io/raw/master/RmPNG/qpt.PNG)
![LE interface](https://github.com/zigzagbob/zigzagbob.github.io/raw/master/RmPNG/qpo.PNG)

## Download ##

Download available at <https://github.com/zigzagbob/QPoisson/releases>.

# Build #

## Pre-installed software ##

### Static Qt compiler ###

Source of static qt compiler: [qt-everywhere-opensource-src-5.4.0-rc](http://download.qt.io/development_releases/qt/5.4/5.4.0-rc/single/qt-everywhere-opensource-src-5.4.0-rc.zip)

Tutorial(in Chinese) of building static qt compiler: <http://zerois.me/id-36.html>

### Dynamic Qt compiler ###

Installation package of dynamic qt compiler: [qt-opensource-windows-x86-msvc2013_opengl-5.4.1](http://download.qt.io/archive/qt/5.4/5.4.1/qt-opensource-windows-x86-msvc2013_opengl-5.4.1.exe)

## Build worker ##

Microsoft Visual Studio 2013 with [qt-vs-addin-1.2.4-opensource](http://download.qt.io/archive/vsaddin/qt-vs-addin-1.2.4-opensource.exe)

## Environment variables ##

QTDIR = "C:\Qt\5.4\msvc2013_opengl"

## Dependencies ##

### MDd ###

qtmaind.lib;Qt5Cored.lib;Qt5Guid.lib;Qt5OpenGLd.lib;opengl32.lib;glu32.lib;Qt5Widgetsd.lib;%(AdditionalDependencies)

### MTd ###

$(QTDIR)\lib\qtmaind.lib;$(QTDIR)\lib\Qt5Widgetsd.lib;$(QTDIR)\plugins\platforms\qwindowsd.lib;winspool.lib;shlwapi.lib;rpcrt4.lib;$(QTDIR)\lib\Qt5PlatformSupportd.lib;$(QTDIR)\plugins\imageformats\qddsd.lib;$(QTDIR)\plugins\imageformats\qicnsd.lib;$(QTDIR)\plugins\imageformats\qicod.lib;$(QTDIR)\plugins\imageformats\qjp2d.lib;$(QTDIR)\plugins\imageformats\qmngd.lib;$(QTDIR)\plugins\imageformats\qtgad.lib;$(QTDIR)\plugins\imageformats\qtiffd.lib;$(QTDIR)\plugins\imageformats\qwbmpd.lib;$(QTDIR)\plugins\imageformats\qwebpd.lib;$(QTDIR)\lib\Qt5Guid.lib;comdlg32.lib;oleaut32.lib;imm32.lib;winmm.lib;glu32.lib;opengl32.lib;gdi32.lib;$(QTDIR)\lib\qtharfbuzzngd.lib;$(QTDIR)\lib\Qt5Cored.lib;kernel32.lib;user32.lib;shell32.lib;uuid.lib;ole32.lib;advapi32.lib;ws2_32.lib;mpr.lib;%(AdditionalDependencies)

### MT ###

$(QTDIR)\lib\qtmain.lib;$(QTDIR)\lib\Qt5Widgets.lib;$(QTDIR)\plugins\platforms\qwindows.lib;winspool.lib;shlwapi.lib;rpcrt4.lib;$(QTDIR)\lib\Qt5PlatformSupport.lib;$(QTDIR)\plugins\imageformats\qdds.lib;$(QTDIR)\plugins\imageformats\qicns.lib;$(QTDIR)\plugins\imageformats\qico.lib;$(QTDIR)\plugins\imageformats\qjp2.lib;$(QTDIR)\plugins\imageformats\qmng.lib;$(QTDIR)\plugins\imageformats\qtga.lib;$(QTDIR)\plugins\imageformats\qtiff.lib;$(QTDIR)\plugins\imageformats\qwbmp.lib;$(QTDIR)\plugins\imageformats\qwebp.lib;$(QTDIR)\lib\Qt5Gui.lib;comdlg32.lib;oleaut32.lib;imm32.lib;winmm.lib;glu32.lib;opengl32.lib;gdi32.lib;$(QTDIR)\lib\qtharfbuzzng.lib;$(QTDIR)\lib\Qt5Core.lib;kernel32.lib;user32.lib;shell32.lib;uuid.lib;ole32.lib;advapi32.lib;ws2_32.lib;mpr.lib;%(AdditionalDependencies)

## Method ##

Core algorithm for blending process is from [SIGGRAPH](https://www.siggraph.org//)'s [`Poisson Image Editing`](http://www.cs.jhu.edu/~misha/Fall07/Papers/Perez03.pdf).

Reference on computing method in detail is at <http://eric-yuan.me/poisson-blending/>. But there is one point in the steps that may make readers misunderstand how to get vector b: the formula of computing b ought to be written as below
```
b[i] = div ( G( Source(x,y) ) ) - Neighbor(target i) ;          i=1..N
```
instead of
```
b[i] = div ( G( Source(x,y) ) ) + Neighbor(target i) ;          i=1..N
```
