# QPoisson
[![license](https://img.shields.io/github/license/MuGeminorum/QPoisson.svg)](https://github.com/MuGeminorum/QPoisson/blob/master/LICENSE)
[![AppVeyor](https://img.shields.io/appveyor/ci/MuGeminorum/QPoisson.svg)](https://ci.appveyor.com/project/MuGeminorum/QPoisson)
[![Github All Releases](https://img.shields.io/github/downloads/MuGeminorum/QPoisson/total.svg)](https://github.com/MuGeminorum/QPoisson/releases)
[![GitHub release](https://img.shields.io/github/release/MuGeminorum/QPoisson.svg)](https://github.com/MuGeminorum/QPoisson/releases/latest)
[![](https://img.shields.io/badge/bilibili-BV1zd4y1J7FG-fc8bab.svg)](https://www.bilibili.com/video/BV1zd4y1J7FG)<br>
Implement Poisson blending algorithm in a simple photo editor with Qt Frame on Windows.

## Usage
| Click ![file_32px_572850_easyicon net](https://user-images.githubusercontent.com/20459298/233123164-23dac4e6-6488-4686-b458-1d5bba09b72e.png) to open dest img, then click ![windows_32px_573226_easyicon net](https://user-images.githubusercontent.com/20459298/233123278-290fe42e-0731-45fe-9d1a-85b876947311.png) to open src img                                                     | ![qps](https://user-images.githubusercontent.com/20459298/233123365-cfa819c6-60e0-4b47-9b7e-12f5b439e513.PNG) |
| :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-----------------------------------------------------------------------------------------------------------: |
| <b>Click ![polygon_32px_1169471_easyicon net](https://user-images.githubusercontent.com/20459298/233123432-9c14faa7-fe41-44f0-9857-0ea282d95cd7.png) to circle an area on src img, then click ![file_transfer_32px_572861_easyicon net](https://user-images.githubusercontent.com/20459298/233123647-b854bb57-391c-4cd6-bf9c-accd84539437.png) to paste the circled area onto dst img</b> | ![qpt](https://user-images.githubusercontent.com/20459298/233123748-3634ce53-28f4-44c6-9d39-9bccfac3fbf3.PNG) |
| <b>Click ![match_width_and_height_32px_572964_easyicon net](https://user-images.githubusercontent.com/20459298/233123837-eb66ca36-32ac-495d-810a-0db32e5a3ba3.png) to blend the pasted area into dst img</b>                                                                                                                                                                              | ![qpo](https://user-images.githubusercontent.com/20459298/233123915-39ee1092-9c09-4e99-9539-e2cd36301e4c.PNG) |

## Maintenance
```bash
git clone https://github.com/MuGeminorum/QPoisson.git
```

## Environment installation, configuration & code debugging, release
Please refer to this [blog post](https://www.cnblogs.com/MuGeminorum/p/17017063.html) for this section.

## Template library
[Template library](https://github.com/MuGeminorum/QPoisson/tree/master/QPoisson/Eigen) from [Eigen](http://eigen.tuxfamily.org);<br>
Eigen is a C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms.

## Method
The core model for the blending process is from [_Poisson Image Editing_](http://www.cs.jhu.edu/~misha/Fall07/Papers/Perez03.pdf).<br>
The formula of computing vector <b><i>b</i></b> is as follow:<br>
```cpp
b[i] = div ( G( Source(x,y) ) ) - Neighbor(target i) ;          i=1..N
```

## License
![enter image description here](https://www.gnu.org/software/mit-scheme/lambda.png)<br>
[Flat icon set](https://github.com/MuGeminorum/QPoisson/tree/master/QPoisson/Resources) from [easyicon](https://www.easyicon.cc);<br>
All source codes are licensed under [MIT License](https://opensource.org/licenses/MIT).<br>
If you want to make any modification on these source codes while keeping new codes unprotected by MIT License, please contact me for a sublicense instead.
