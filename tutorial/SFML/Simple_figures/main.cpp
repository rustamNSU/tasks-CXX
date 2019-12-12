#include <SFML/Graphics.hpp>

using namespace sf;
int main(){
    
    // Set antialiasing level
    ContextSettings settings;
    settings.antialiasingLevel = 8;

    // A window in which graphics are drawn
    RenderWindow window(VideoMode(600, 300), "SFML Works!",
        Style::Default, settings);

    while (window.isOpen())
    {
        // event queue in the loop
        Event event;
        while (window.pollEvent(event))
        {
            // Close window
            if (event.type == Event::Closed){
                window.close();
            }
        }

        // Background color
        window.clear( Color(250,220,100,0));

        // Make a circle
        CircleShape circle(50.);

        // Solid circle
        circle.setFillColor(Color(230,0,230));

        // Thickness of boundary
        circle.setOutlineThickness(15.f);

        // Color of boundary
        circle.setOutlineColor(Color(80,220,50,200));

        // Move circle center
        circle.move(30,30);

        // Drawing circle in window
        window.draw(circle);


        // Triangle from CircleShape
		CircleShape triangle(70.f, 3);
        triangle.setPosition(125, 0);
		triangle.setFillColor(Color::Blue);
		window.draw(triangle);

        // Square
        CircleShape square(60.f, 4);
		square.setPosition(250, 0);
		square.setFillColor(Color::Red);
		window.draw(square);

        // Octagon
        CircleShape octagon(60.f, 8);
		octagon.setPosition(380, 0);
		octagon.setFillColor(Color::Cyan);
		window.draw(octagon);

        ConvexShape convex;
        convex.setPointCount(5);

        // Verticles definition
        convex.setPoint(0, Vector2f(0.f, 0.f));
        convex.setPoint(1, Vector2f(150.f, 10.f));
        convex.setPoint(2, Vector2f(120.f, 90.f));
        convex.setPoint(3, Vector2f(30.f, 100.f));
        convex.setPoint(4, Vector2f(5.f, 50.f));

        convex.setFillColor(Color::Black);
        convex.move(1,150);
        window.draw(convex);

        RectangleShape rectangle(Vector2f(70.f, 100.f));
        rectangle.move(165,150);
        rectangle.setFillColor(Color::Yellow);
        window.draw(rectangle);

        // For draw lines uses rectangle
        RectangleShape line_with_thickness(Vector2f(130.f, 5.f));

        line_with_thickness.rotate(45.f);
        line_with_thickness.setFillColor(Color(15,180,140));
        line_with_thickness.move(250,150);
        window.draw(line_with_thickness);

        // Zero thickness line
        Vertex line_without_thickness[] =
        {
            Vertex(Vector2f(390.f, 240.f)),
            Vertex(Vector2f(470.f, 150.f))
        };

        line_without_thickness->color = Color::Black;
        window.draw(line_without_thickness, 2, Lines);



        // 
        window.display();
    }

    return 0;
}