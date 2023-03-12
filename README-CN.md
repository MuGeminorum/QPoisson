# QPoisson

在 Windows 上使用 C++ Qt 框架在简单的照片编辑器中实现泊松融合算法。

[![license](https://img.shields.io/github/license/george-chou/QPoisson.svg)](https://github.com/george-chou/QPoisson/blob/master/LICENSE)
[![AppVeyor](https://img.shields.io/appveyor/ci/george-chou/QPoisson.svg)](https://ci.appveyor.com/project/george-chou/QPoisson)
[![Github All Releases](https://img.shields.io/github/downloads/george-chou/QPoisson/total.svg)](https://github.com/george-chou/QPoisson/releases)
[![GitHub release](https://img.shields.io/github/release/george-chou/QPoisson.svg)](https://github.com/george-chou/QPoisson/releases/latest)

## 使用方法

<a href="https://www.bilibili.com/video/BV1zd4y1J7FG?p=1" target="_blank">Demo视频</a>

| 点击 <img src='https://picrepo.netlify.app/QPoisson/file_32px_572850_easyicon.net.ico' /> 打开目标图片，再点击 <img src='https://picrepo.netlify.app/QPoisson/windows_32px_573226_easyicon.net.ico' /> 打开源图片                                            | <img src="https://picrepo.netlify.app/QPoisson/qps.PNG"/> |
| :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------------------------------: |
| <b>点击 <img src='https://picrepo.netlify.app/QPoisson/polygon_32px_1169471_easyicon.net.ico' /> 在源图片上圈出一多边形区域，再点击 <img src='https://picrepo.netlify.app/QPoisson/file_transfer_32px_572861_easyicon.net.ico' /> 将该区域贴到目标图片上</b> | <img src="https://picrepo.netlify.app/QPoisson/qpt.PNG"/> |
| <b>点击 <img src='https://picrepo.netlify.app/QPoisson/match_width_and_height_32px_572964_easyicon.net.ico' /> 将贴图融合进目标图片</b>                                                                                                                      | <img src="https://picrepo.netlify.app/QPoisson/qpo.PNG"/> |

## 代码下载
```
git clone https://github.com/george-chou/QPoisson.git
```

## 环境安装

### 必要项下载

| 必要项                  | 链接                                                                                                                                     |
| :---------------------- | :--------------------------------------------------------------------------------------------------------------------------------------- |
| Qt 5.7 动态编译器       | [qt-opensource-windows-x86-msvc2015-5.7.1](https://download.qt.io/new_archive/qt/5.7/5.7.1/qt-opensource-windows-x86-msvc2015-5.7.1.exe) |
| 编译好的Qt5.7静态编译器 | [qt5-x86-static-release](https://pan.baidu.com/s/1hhDt9MIG0PfcXXFaZrHyRw?pwd=iUgO)                                                       |
| Visual Studio 2015      | [Microsoft Visual Studio 2015](https://pan.baidu.com/s/15CQKY6LhU_xATe8Ra9r4jw?pwd=0pwH)                                                 |
| Qt VS AddIn             | [qt-vsaddin-msvc2015-2.4.3.vsix](https://download.qt.io/archive/vsaddin/2.4.3/qt-vsaddin-msvc2015-2.4.3.vsix)                            |
| MinGW                   | [mingw-w64-install.exe](https://pan.baidu.com/s/1d0tPdiGStfAoYIk4FAfiig?pwd=BWll)                                                        |
| Visual Studio Code      | <https://code.visualstudio.com/Download>                                                                                                 |

### 安装顺序

1. 安装 Qt 5.7 动态编译器
2. 安装 Visual Studio 2015
3. 安装 Qt VS AddIn
4. 安装 MinGW
5. 安装 Visual Studio Code

## 环境配置

### 附加依赖项配置

1. 用 VS2015 打开工程，右键 `项目` - `属性`
2. 配置选择 `活动(Release)`
3. 打开 `配置属性` - `C/C++` - `代码生成` - `运行库` 选择 `多线程(/MT)`
4. 打开 `配置属性` - `链接器` - `输入` - `附加依赖项` ，将下述长串字符粘贴进去：

`$(QTDIR)\lib\qtmain.lib;$(QTDIR)\lib\Qt5Widgets.lib;$(QTDIR)\plugins\platforms\qwindows.lib;winspool.lib;shlwapi.lib;rpcrt4.lib;$(QTDIR)\lib\Qt5PlatformSupport.lib;$(QTDIR)\plugins\imageformats\qdds.lib;$(QTDIR)\plugins\imageformats\qicns.lib;$(QTDIR)\plugins\imageformats\qico.lib;$(QTDIR)\plugins\imageformats\qtga.lib;$(QTDIR)\plugins\imageformats\qtiff.lib;$(QTDIR)\plugins\imageformats\qwbmp.lib;$(QTDIR)\plugins\imageformats\qwebp.lib;$(QTDIR)\lib\Qt5Gui.lib;comdlg32.lib;oleaut32.lib;imm32.lib;winmm.lib;glu32.lib;opengl32.lib;gdi32.lib;$(QTDIR)\lib\qtharfbuzzng.lib;$(QTDIR)\lib\Qt5Core.lib;kernel32.lib;user32.lib;shell32.lib;uuid.lib;ole32.lib;advapi32.lib;ws2_32.lib;mpr.lib`

### Qt 配置

1. 完成前一步的附加依赖项配置
2. 解压编译好的 Qt 静态编译器 `qt5-x86-static-release`
3. 用 VS2015 打开工程，点击 `[Qt VS Tools]` -> `[Qt Options]` -> `[Add]`，选择前面解压好的 Qt 静态编译器路径并确定
4. 在 `[Default Qt/Win version]` 下拉菜单中选择 `qt5-x86-static-release`，点 OK

## 调试

1. 右键工程目录以 VSCode 打开工程
2. 确认工程中 `c_cpp_properties.json` 的 `includePath` 正确配置了前面安装的 `Qt 5.7 动态编译器`路径，同时 `compilerPath` 正确配置了 `MinGW` 的环境变量路径
3. 点击 `运行` - `启动调试` (或直接键盘按F5开启Debug模式)

## 发布

1. 用 VS2015 打开工程
2. 选择 `Release` 模式 `x86`
3. 选择 `生成` - `重新生成解决方案`
4. 在工程目录下的 Release 中取出 .exe 文件，即为用于发布的文件

## 模板库

[模板库](https://github.com/george-chou/QPoisson/tree/master/QPoisson/Eigen) 选择的是 [Eigen库](http://eigen.tuxfamily.org)

Eigen 是一个用于线性代数的 C++ 模板库：是矩阵、向量的数值求解器，包含诸多相关算法。

## 方法

<a href="https://www.bilibili.com/video/BV1zd4y1J7FG?p=2" target="_blank">视频版介绍</a>

核心融合算法参考于 [_Poisson Image Editing_](http://www.cs.jhu.edu/~misha/Fall07/Papers/Perez03.pdf)

其中向量 <b><i>b</i></b> 的计算公式如下：
```
b[i] = div ( G( Source(x,y) ) ) - Neighbor(target i) ;          i=1..N
```

## 许可证

<a href="https://opensource.org/licenses/MIT" target="_blank">
    <img src="https://www.gnu.org/software/mit-scheme/lambda.png" />
</a>

[平面图标集](https://github.com/george-chou/QPoisson/tree/master/QPoisson/Resources) 来源于 [easyicon](https://www.easyicon.cc/)
