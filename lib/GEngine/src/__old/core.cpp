// #include "core.h"
// #include "__old/Shape/Shape.h"
// #include "Adafruit_SSD1306.h"

// GEngine::GEngine(vec28u size)
//     : Adafruit_SSD1306(size.x, size.y),
//       size(size),
//       center(size / 2)
// {
//     while (!begin(SSD1306_SWITCHCAPVCC, 0x3c))
//         ;

//     clearDisplay();
// }

// void GEngine::put()
// {
//     for (int i = 0; i < objects.size(); i++)
//     {
//         if (objects[i]->visible)
//         {
//             objects[i]->draw();
//         }
//     }
//     display();
//     clearDisplay();
// }

// void GEngine::add_obj(IShape *shape)
// {
//     objects.push(shape);
//     shape->scene = this;
// }

// void GEngine::delete_obj(IShape *obj)
// {
//     for (int i = 0; i < objects.size(); i++)
//     {
//         if (obj == objects[i])
//         {
//             objects.del(&obj);
//         }
//     }
// }

// // void GEngine::add_obj_arr(Array<IShape *> obj_arr)
// // {
// //     for (int i = 0; i < )
// //         objects.push(obj_arr);
// // }

// void GEngine::pix(vec28u p)
// {
//     drawPixel(p.x, p.y, 1);
// }