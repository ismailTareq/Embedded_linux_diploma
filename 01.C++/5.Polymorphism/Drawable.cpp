#include <bits/stdc++.h>

class Drawable
{
private:

public:
    virtual void draw() = 0;

    virtual ~Drawable() = default;
};

class Rectangle : public Drawable
{
private:
    int height;
    int width;
public:
    Rectangle(int h,int w)
    :height(h),width(w)
    {

    }
    void draw()
    {
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                std::cout << '*';
            }
        std::cout << std::endl;
        }
    }
    virtual ~Rectangle() = default;
};

class Circle : public Drawable
{
private:
    int radius;
public:
    Circle(int r)
    :radius(r)
    {

    }
    void draw()
    {
        double aspect_ratio = 2.5;
        for (int y = radius; y >= -radius; --y)
        {
            for (int x = -radius * aspect_ratio; x <= radius * aspect_ratio; ++x)
            {
                double distance = (x / aspect_ratio) * (x / aspect_ratio) + y * y;
                if (distance <= radius * radius)
                    std::cout << '*';
                else
                    std::cout << ' ';
            }
            std::cout << std::endl;
        }
    }
    ~Circle() = default;
};

class Triangle : public Drawable
{
private:
    int height;
public:
    Triangle(int h)
    :height(h)
    {

    }
    void draw()
    {
        int width = 2 * height - 1;

        for (int i = 0; i < height; ++i)
        {
            int numStars = 2 * i + 1;
            int numSpaces = (width - numStars) / 2;
            for (int j = 0; j < numSpaces; ++j)
            {
                std::cout << ' ';
            }
            for (int j = 0; j < numStars; ++j)
            {
                std::cout << '*';
            }
            for (int j = 0; j < numSpaces; ++j)
            {
                std::cout << ' ';
            }
            std::cout << std::endl;
        }
    }
    ~Triangle() = default;
};

int main()
{
    Drawable* shapes;

    shapes =  new Circle(3);

    shapes->draw();

    delete shapes;

    std::cout << std::endl;

    shapes =  new Triangle(10);

    shapes->draw();

    delete shapes;

    std::cout << std::endl;

    shapes =  new Rectangle(5,20);

    shapes->draw();

    delete shapes;

    std::cout << std::endl;

}
