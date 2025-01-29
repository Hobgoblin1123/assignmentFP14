#define WIDTH 300
#define HEIGHT 200
struct color
{
    unsigned char r, g, b;
};
void img_clear(void);
void img_write(void);
void img_putpixel(struct color c, int x, int y);
void img_fillcircle(struct color c, double x, double y, double r);
void gradation_square(struct color c, struct color d, double x, double y, double r, int steps); //(下端の色, 上端の色, 中心x, 中心y, 一辺の長さ, 色の遷移回数=フレーム数)
void img_circle(struct color c, double x, double y, double r);
void img_square(struct color c, double x, double y, double s, double t);
void img_asteroid(struct color c, double x, double y, double r);
void write_Uoutside(void);
void write_Uinside(void);
void write_Eoutside(void);
void write_Einside(void);
void write_Coutside(void);
void write_Cinside(void);
void img_ellipse(struct color c, double x, double y, double a, double b, double theta);
void img_fillellipse(struct color c, double x, double y, double a, double b, double theta);
void move_circle(struct color c, double x, double y, double a, double b, double theta, struct color d, double r);
void write_outellipse(void);
void write_inellipse(void);