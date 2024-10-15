class Rectangle {
private:
    double width;
    double height;
    static double totalArea;

public:
    Rectangle(double, double);

    double getHeight() const;
    double getWidth() const;
    void setWidth(double);
    void setHeight(double);

    static double getTotalArea();
};