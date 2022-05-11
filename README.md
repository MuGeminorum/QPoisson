# QPoisson

Poisson Blending in Qt Frame

[![license](https://img.shields.io/github/license/george-chou/QPoisson.svg)](https://github.com/george-chou/QPoisson/blob/master/LICENSE)
[![AppVeyor](https://img.shields.io/appveyor/ci/george-chou/QPoisson.svg)](https://ci.appveyor.com/project/george-chou/QPoisson)
[![Github All Releases](https://img.shields.io/github/downloads/george-chou/QPoisson/total.svg)](https://github.com/george-chou/QPoisson/releases)
[![GitHub release](https://img.shields.io/github/release/george-chou/QPoisson.svg)](https://github.com/george-chou/QPoisson/releases/latest)

Implement Poisson blending algorithm in a simple photo editor with Qt Frame.

<div align=center>
    <img width="605" src="https://george-chou-github-io.vercel.app/covers/QPoisson/qps.PNG"/>
    <br><b>↓</b><br>
    <img width="605" src="https://george-chou-github-io.vercel.app/covers/QPoisson/qpt.PNG"/>
    <br><b>↓</b><br>
    <img width="605" src="https://george-chou-github-io.vercel.app/covers/QPoisson/qpo.PNG"/>
</div>

## Download ##

Download available at <https://github.com/george-chou/QPoisson/releases>;

# Build #

## Pre-installed software ##

### Static Qt compiler ###

Compiled static qt compiler: [precompiled-qt4-qt5](https://www.npcglib.org/~stathis/blog/precompiled-qt4-qt5/)

### Dynamic Qt compiler ###

Installation package of dynamic qt compiler: [qt-opensource-windows-x86-msvc2015-5.7.1](https://download.qt.io/new_archive/qt/5.7/5.7.1/qt-opensource-windows-x86-msvc2015-5.7.1.exe)

## Build worker ##

Microsoft Visual Studio 2015 with [qt-vsaddin-msvc2015-2.4.3.vsix](https://download.qt.io/archive/vsaddin/2.4.3/qt-vsaddin-msvc2015-2.4.3.vsix)

## Requirement

Compiler for VSCode: [mingw-w64-install.exe](https://www.123pan.com/s/qeQDVv-3ZFJH)

Extraction code: BWll

## Dependencies ##

用VS2015打开工程 - 右键项目 - 属性

配置选择 活动(Release)

打开 配置属性 - C/C++ - 代码生成 - 运行库 选择 多线程(/MT)

打开 配置属性 - 链接器 - 输入 - 附加依赖项 将下述 MT 下的长串字符粘贴进去

确定

### MT ###

`$(QTDIR)\lib\qtmain.lib;$(QTDIR)\lib\Qt5Widgets.lib;$(QTDIR)\plugins\platforms\qwindows.lib;winspool.lib;shlwapi.lib;rpcrt4.lib;$(QTDIR)\lib\Qt5PlatformSupport.lib;$(QTDIR)\plugins\imageformats\qdds.lib;$(QTDIR)\plugins\imageformats\qicns.lib;$(QTDIR)\plugins\imageformats\qico.lib;$(QTDIR)\plugins\imageformats\qtga.lib;$(QTDIR)\plugins\imageformats\qtiff.lib;$(QTDIR)\plugins\imageformats\qwbmp.lib;$(QTDIR)\plugins\imageformats\qwebp.lib;$(QTDIR)\lib\Qt5Gui.lib;comdlg32.lib;oleaut32.lib;imm32.lib;winmm.lib;glu32.lib;opengl32.lib;gdi32.lib;$(QTDIR)\lib\qtharfbuzzng.lib;$(QTDIR)\lib\Qt5Core.lib;kernel32.lib;user32.lib;shell32.lib;uuid.lib;ole32.lib;advapi32.lib;ws2_32.lib;mpr.lib`

发布方法：

选择 Release 模式 Win32

右键项目，选择 Qt Project Settings

Version 选择 qt5-x86-static-release

OK

选择 生成 - 重新生成解决方案

在工程目录下的 Release 中取出 .exe

## Template library ##

[Template library](https://github.com/george-chou/QPoisson/tree/master/QPoisson/Eigen) from [Eigen](http://eigen.tuxfamily.org);

Eigen is a C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms.

## Method ##

The core model for the blending process is from [_Poisson Image Editing_](http://www.cs.jhu.edu/~misha/Fall07/Papers/Perez03.pdf).

The formula of computing vector <b><i>b</i></b> is as follow:
```
b[i] = div ( G( Source(x,y) ) ) - Neighbor(target i) ;          i=1..N
```

## License ##

![enter image description here](https://www.gnu.org/software/mit-scheme/lambda.png)

[Flat icon set](https://github.com/george-chou/QPoisson/tree/master/QPoisson/Resources) from [easyicon](https://www.easyicon.net/);

All source codes are licensed under [MIT License](https://opensource.org/licenses/MIT).

If you want to make any modification on these source codes while keeping new codes unprotected by MIT License, please contact me for a sublicense instead.
