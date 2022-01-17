/*program name:mean.h
programmer:吕炎明
student number:19301014
date:2020-07-11
use:包含棋子定义、图片转化函数定义的自定义头文件
*/

#include <easyx.h>
#include <conio.h>

enum Status {//定义该点的落子情况
	StatusBlank = -1,
	StatusBlack = 0,
	StatusWhite = 1
};


//显示图片函数
void drawAlpha(IMAGE*, int, int); //使png格式的图片背景透明


