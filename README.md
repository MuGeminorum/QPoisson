# QPoisson

Implement Poisson blending algorithm in a simple photo editor with Qt Frame on Windows.

[![license](https://img.shields.io/github/license/george-chou/QPoisson.svg)](https://github.com/george-chou/QPoisson/blob/master/LICENSE)
[![AppVeyor](https://img.shields.io/appveyor/ci/george-chou/QPoisson.svg)](https://ci.appveyor.com/project/george-chou/QPoisson)
[![Github All Releases](https://img.shields.io/github/downloads/george-chou/QPoisson/total.svg)](https://github.com/george-chou/QPoisson/releases)
[![GitHub release](https://img.shields.io/github/release/george-chou/QPoisson.svg)](https://github.com/george-chou/QPoisson/releases/latest)

## Usage

| Click <img src='https://picrepo.netlify.app/QPoisson/file_32px_572850_easyicon.net.ico' /> to open dest img, then click <img src='https://picrepo.netlify.app/QPoisson/windows_32px_573226_easyicon.net.ico' /> to open src img                                                     | <img src="https://picrepo.netlify.app/QPoisson/qps.PNG"/> |
| :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------------------------------: |
| <b>Click <img src='https://picrepo.netlify.app/QPoisson/polygon_32px_1169471_easyicon.net.ico' /> to circle an area on src img, then click <img src='https://picrepo.netlify.app/QPoisson/file_transfer_32px_572861_easyicon.net.ico' /> to paste the circled area onto dst img</b> | <img src="https://picrepo.netlify.app/QPoisson/qpt.PNG"/> |
| <b>Click <img src='https://picrepo.netlify.app/QPoisson/match_width_and_height_32px_572964_easyicon.net.ico' /> to blend the pasted area into dst img</b>                                                                                                                           | <img src="https://picrepo.netlify.app/QPoisson/qpo.PNG"/> |

## Code download
```
git clone https://github.com/george-chou/QPoisson.git
```

## Environment installation, configuration & code debugging, release
Please refer to this [blog post](https://www.cnblogs.com/georgechou/p/17017063.html) for this section.

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

[Flat icon set](https://github.com/george-chou/QPoisson/tree/master/QPoisson/Resources) from [easyicon](https://www.easyicon.cc);

All source codes are licensed under [MIT License](https://opensource.org/licenses/MIT).

If you want to make any modification on these source codes while keeping new codes unprotected by MIT License, please contact me for a sublicense instead.
