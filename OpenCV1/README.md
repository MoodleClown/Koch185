# kochIzobrashenie03.09.2021
1. Скачать Open CV с сайта https://opencv.org/releases/ и выбрать версию для Windows. 
2. После устанавливаем Open CV 
3. Создаем пустой проект C++ 
4. Кликаем по названию проекта и кликаем на "Добавить"  --> Создать элемент --> Файл C++(.cpp)
5. После этого по названию проекта кликаем правой кнопкой мыши и выбираем "Свойства" 
6. Находим C/C++ --> Раскрываем и находим "Общие" --> Находим каталоги включаемых файлов --> указываем путь openCv "...\opencv\build\include"
7. Далее выбираем "Компоновщик" --> "Общие" --> "Дополнительные каталоги библиотек" --> указываем путь "...\opencv\build\x64\vc15\lib"
8. Во все том же "Компоновщик" находим "Ввод" --> "Дополнительные зависимости и из папки lib выбираем opencv_world453.lib
opencv_world453d.lib
// все сделанное должно быть выполнено на платформе x64
9. Из папки "...opencv\build\x64\vc15\bin" копируете opencv_world453.dll и opencv_world453d.dll в папку  C:\...\source\repos\(Название вашего проекта\Debug
10. Полностью переписываем исходный код кроме строчки namedWindow("Hello world", 0);
Запускаем и получаем изображение.
