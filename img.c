#include <stdio.h>
#include <stdlib.h>
#include "img.h"
#include <math.h>

static unsigned char buf[HEIGHT][WIDTH][3];
static int filecnt = 0;
static char fname[100];

void img_clear(void)
{
  int i, j;
  for (j = 0; j < HEIGHT; ++j)
  {
    for (i = 0; i < WIDTH; ++i)
    {
      buf[j][i][0] = buf[j][i][1] = buf[j][i][2] = 255;
    }
  }
}

void img_write(void)
{
  sprintf(fname, "img%04d.ppm", ++filecnt);
  FILE *f = fopen(fname, "wb");
  if (f == NULL)
  {
    fprintf(stderr, "can't open %s\n", fname);
    exit(1);
  }
  fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
  fwrite(buf, sizeof(buf), 1, f);
  fclose(f);
}

void img_putpixel(struct color c, int x, int y)
{
  if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
  {
    return;
  }
  buf[HEIGHT - y - 1][x][0] = c.r;
  buf[HEIGHT - y - 1][x][1] = c.g;
  buf[HEIGHT - y - 1][x][2] = c.b;
}

void img_fillcircle(struct color c, double x, double y, double r)
{
  int imin = (int)(x - r - 1), imax = (int)(x + r + 1);
  int jmin = (int)(y - r - 1), jmax = (int)(y + r + 1);
  int i, j;
  for (j = jmin; j <= jmax; ++j)
  {
    for (i = imin; i <= imax; ++i)
    {
      if ((x - i) * (x - i) + (y - j) * (y - j) <= r * r)
      {
        img_putpixel(c, i, j);
      }
    }
  }
}

void img_circle(struct color c, double x, double y, double r)
{
  int imin = (int)(x - r - 1), imax = (int)(x + r + 1);
  int jmin = (int)(y - r - 1), jmax = (int)(y + r + 1);
  int i, j;
  for (j = jmin; j <= jmax; ++j)
  {
    for (i = imin; i <= imax; ++i)
    {
      if ((x - i) * (x - i) + (y - j) * (y - j) == r * r)
      {
        img_putpixel(c, i, j);
      }
    }
  }
}

void img_square(struct color c, double x, double y, double s, double t)
{
  int imin = (int)(x - s - 1), imax = (int)(x + s + 1);
  int jmin = (int)(y - t - 1), jmax = (int)(y + t + 1);
  int i, j;
  for (j = jmin; j <= jmax; ++j)
  {
    for (i = imin; i <= imax; ++i)
    {
      img_putpixel(c, i, j);
    }
  }
}

void img_asteroid1(struct color c, double x, double y, double r)
{
  int imin = (int)(x - r - 1), imax = (int)(x + r + 1);
  int jmin = (int)(y - r - 1), jmax = (int)(y + r + 1);
  int i, j;
  for (j = jmin; j <= jmax; ++j)
  {
    for (i = imin; i <= imax; ++i)
    {
      if (pow(i - x, 2 / 2.7) + pow(j - y, 2 / 2.7) <= pow(r, 2 / 2.7))
      {
        img_putpixel(c, i, j);
      }
    }
  }
}

void img_asteroid2(struct color c, double x, double y, double r)
{
  int imin = (int)(-x - r - 1), imax = (int)(-x + r + 1);
  int jmin = (int)(y - r - 1), jmax = (int)(y + r + 1);
  int i, j;
  for (j = jmin; j <= jmax; ++j)
  {
    for (i = imin; i <= imax; ++i)
    {
      if (pow(i - x, 2 / 2.7) + pow(j - y, 2 / 2.7) <= pow(r, 2 / 2.7))
      {
        img_putpixel(c, i, j);
      }
    }
  }
}

void write_Uinside(void)
{
  struct color c2 = {255,255,255};
  img_square(c2,77.5,115,22.5,35);
  img_fillellipse(c2,77.5,80,22.5,20,0);
  img_asteroid1(c2,39,49,30);
}

void write_Eoutside(void)
{
  // graduation_square(c1, 150, 100, 30, 50);
}

void write_Einside(void)
{
  struct color c2 = {255, 255, 255};
  img_square(c2, 157.5, 122.5, 22.5, 17.5);
  img_square(c2, 175, 100, 5, 5);
  img_square(c2, 157.5, 77.5, 22.5, 17.5);
}

void write_Coutside(void)
{
  // graduation_square(c1, 225, 100, 35, 50);
}

void write_Cinside(void)
{
  struct color c2 = {255, 255, 255};
  img_square(c2, 235, 100, 25, 30);
  img_fillellipse(c2, 230, 130, 20, 10, 0);
  img_fillellipse(c2, 230, 70, 20, 10, 0);
}

void write_outellipse(void)
{
  struct color c1 = {0, 0, 255};
  img_fillellipse(c1, 150, 100, 120, 65, 30);
}

void write_inellipse(void)
{
  struct color c2 = {255, 255, 255};
  img_fillellipse(c2, 150, 100, 117, 62, 29);
}