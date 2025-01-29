#define WIDTH 300
#define HEIGHT 200
struct color { unsigned char r, g, b; };
void img_clear(void);
void img_write(void);
void img_putpixel(struct color c, int x, int y);
void img_fillcircle(struct color c, double x, double y, double r);
void gradation_square(struct color c, struct color d, double x,double y, double r, int steps);  //(下端の色, 上端の色, 中心x, 中心y, 一辺の長さ, 色の遷移回数=フレーム数)
void img_circle(struct color c, double x, double y, double r);
void write_U(void);
void write_E(void);
void write_C(void);
