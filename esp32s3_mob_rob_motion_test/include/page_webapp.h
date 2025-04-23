/**
 * \file page_webapp.h
 * \author Sckom
 * \brief 
 * \version 0.1
 * \date 2025-03-28
 * 
 * \copyright Copyright (c) 2025
 * 
 */

#ifndef WEB_APP_CONFIG_H
#define WEB_APP_CONFIG_H

#include <Arduino.h>

// SSID существующей сети WiFI
static const char* ssid = "RoboticsLab1";     // Enter your exist WiFi ssid here
// Password существующей сети WiFI
static const char* password = "RoboticsLab1"; // Enter your exist WiFi password here
// DNS для переименования URL сервера в составе существующей сети WiFI в виде <DNS>.local
static const char* nameDNS = "mrp"; // Enter your DNS here
// Код для WebApp с хранением в памяти программы (ПЗУ)
static const char HTML[] PROGMEM = R"=====(<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Config wheels</title>
    <style>
        body {
            margin: 0;
            font-family: Arial, sans-serif;
            background-color: rgb(40, 40, 40);
            color: rgb(255, 255, 255);
        }
        .container {
            display: flex;
            flex-wrap: wrap;
            gap: 16px;
            padding: 16px;
        }
        .item {
            flex: 1 1 20%;
            /* Четыре колонки */
            box-sizing: border-box;
            background: #2196f3;
            color: white;
            padding: 20px;
            text-align: center;
            border-radius: 8px;
        }
        .title_text {
            text-align: center;
            font-size: 16pt;
            position: relative;
            margin-top: 10pt;
        }
        \media (max-width: 656px) {
            .item {
                flex: 2 2 20%;
                /* Две колонки на меньших экранах */
            }
        }
        \media (max-width: 583px) {
            .item {
                flex: auto;
            }
        }
        \media (max-width: 480px) {
            .item {
                flex: 1 1 100%;
                /* Одна колонка на мобильных экранах */
            }
        }
    </style>
    <script>
        const selects = document.querySelectorAll('.ch_wheel');
        const selectedValues = new Set();
        var i = 0;
        selects.forEach(select => {
            select.value = select.value + i;
            i++;
        });
    </script>
</head>
<body>
    <header>
        <div class="title_text">Configuration wheels</div>
    </header>

    <div class="container">
        <div class="item">
            <label for="inp_wheel_1">Wheel_1</label>
            <input type="range" id="inp_wheel_1" min="-100" max="100" value="0" step="5" onchange="ch_wheel_1()" />
            <div class="output" id="out_wheel_1">0</div>
            <button id="ch_wh_1" onchange="rev_data_wh_1()">+</button>
        </div>
        <div class="item">
            <label for="inp_wheel_2">Wheel_2</label>
            <input type="range" id="inp_wheel_2" min="-100" max="100" value="0" step="5" onchange="ch_wheel_2()" />
            <div class="output" id="out_wheel_2">0</div>
            <button id="ch_wh_2" onchange="rev_data_wh_2()">+</button>
        </div>
        <div class="item">
            <label for="inp_wheel_3">Wheel_3</label>
            <input type="range" id="inp_wheel_3" min="-100" max="100" value="0" step="5" onchange="ch_wheel_3()" />
            <div class="output" id="out_wheel_3">0</div>
            <button id="ch_wh_3" onchange="rev_data_wh_3()">+</button>
        </div>
        <div class="item">
            <label for="inp_wheel_4">Wheel_4</label>
            <input type="range" id="inp_wheel_4" min="-100" max="100" value="0" step="5" onchange="ch_wheel_4()" />
            <div class="output" id="out_wheel_4">0</div>
            <button id="ch_wh_4" onchange="rev_data_wh_4()">+</button>
        </div>
    </div>
    <div class="container">
        <div class="item">
            Forward Left:
            <form class="form_wheel_1">
                <select class="ch_wheel">
                    <option value="Wheel_1" selected>Wheel 1</option>
                    <option value="Wheel_2">Wheel 2</option>
                    <option value="Wheel_3">Wheel 3</option>
                    <option value="Wheel_4">Wheel 4</option>
                </select>
            </form>
        </div>
        <div class="item">
            Forward Right:
            <form class="form_wheel_2">
                <select class="ch_wheel">
                    <option value="Wheel_1">Wheel 1</option>
                    <option value="Wheel_2" selected>Wheel 2</option>
                    <option value="Wheel_3">Wheel 3</option>
                    <option value="Wheel_4">Wheel 4</option>
                </select>
            </form>
        </div>
        <div class="item">
            Backward Left:
            <form class="form_wheel_3">
                <select class="ch_wheel">
                    <option value="Wheel_1">Wheel 1</option>
                    <option value="Wheel_2">Wheel 2</option>
                    <option value="Wheel_3" selected>Wheel 3</option>
                    <option value="Wheel_4">Wheel 4</option>
                </select>
            </form>
        </div>
        <div class="item">
            Backward Right:
            <form class="form_wheel_4">
                <select class="ch_wheel">
                    <option value="Wheel_1">Wheel 1</option>
                    <option value="Wheel_2">Wheel 2</option>
                    <option value="Wheel_3">Wheel 3</option>
                    <option value="Wheel_4" selected>Wheel 4</option>
                </select>
            </form>
        </div>
    </div>
    <div class="container">
        <button class="item" id="confirm_data">CONFIRM</button>
    </div>
    <script>
        // Коэффициент для данных слайдера колеса 1
        var inv_data_wheel_1 = 1;
        // Коэффициент для данных слайдера колеса 2
        var inv_data_wheel_2 = 1;
        // Коэффициент для данных слайдера колеса 3
        var inv_data_wheel_3 = 1;
        // Коэффициент для данных слайдера колеса 4
        var inv_data_wheel_4 = 1;
        /* Функция инвертирования данных слайдера колеса 1 */
        function rev_data_wh_1(bt) {
            inv_data_wheel_1 = inv_data_wheel_1 * -1;
            let a = document.getElementById(bt);
            if (inv_data_wheel_1 == 1) {
                a.textContent = "+";
            }
            else {
                a.textContent = "-";
            }
            updateSpeedValWheel("inp_wheel_1", "out_wheel_1", inv_data_wheel_1);
            /* Отправка GET запроса от клиента к серверу (микроконтроллеру) */
            request = new XMLHttpRequest();
            request.open('GET', '/wheel_1?inv_1=' + "1", false);
            request.send();
            console.log("inv_data_wheel_1: " + inv_data_wheel_1);
        }
        /* Функция инвертирования данных слайдера колеса 2 */
        function rev_data_wh_2(bt) {
            inv_data_wheel_2 = inv_data_wheel_2 * -1;
            let a = document.getElementById(bt);
            if (inv_data_wheel_2 == 1) {
                a.textContent = "+";
            }
            else {
                a.textContent = "-";
            }
            updateSpeedValWheel("inp_wheel_2", "out_wheel_2", inv_data_wheel_2);
            /* Отправка GET запроса от клиента к серверу (микроконтроллеру) */
            request = new XMLHttpRequest();
            request.open('GET', '/wheel_2?inv_2=' + "1", false);
            request.send();
            console.log("inv_data_wheel_2: " + inv_data_wheel_2);
        }
        /* Функция инвертирования данных слайдера колеса 3 */
        function rev_data_wh_3(bt) {
            inv_data_wheel_3 = inv_data_wheel_3 * -1;
            let a = document.getElementById(bt);
            if (inv_data_wheel_3 == 1) {
                a.textContent = "+";
            }
            else {
                a.textContent = "-";
            }
            updateSpeedValWheel("inp_wheel_3", "out_wheel_3", inv_data_wheel_3);
            /* Отправка GET запроса от клиента к серверу (микроконтроллеру) */
            request = new XMLHttpRequest();
            request.open('GET', '/wheel_3?inv_3=' + "1", false);
            request.send();
            console.log("inv_data_wheel_3: " + inv_data_wheel_3);
        }
        /* Функция инвертирования данных слайдера колеса 4 */
        function rev_data_wh_4(bt) {
            inv_data_wheel_4 = inv_data_wheel_4 * -1;
            let a = document.getElementById(bt);
            if (inv_data_wheel_4 == 1) {
                a.textContent = "+";
            }
            else {
                a.textContent = "-";
            }
            updateSpeedValWheel("inp_wheel_4", "out_wheel_4", inv_data_wheel_4);
            /* Отправка GET запроса от клиента к серверу (микроконтроллеру) */
            request = new XMLHttpRequest();
            request.open('GET', '/wheel_4?inv_4=' + "1", false);
            request.send();
            console.log("inv_data_wheel_4: " + inv_data_wheel_4);
        }
        /* Функция отправки данных по изменении данных слайдера для колеса 1 */
        function ch_wheel_1() {
            // Значение слайдера колеса 1
            const wheel_1 = document.getElementById("inp_wheel_1").value * inv_data_wheel_1;
            console.log("wheel_1: " + wheel_1);

            /* Отправка GET запроса от клиента к серверу (микроконтроллеру) */
            request = new XMLHttpRequest();
            request.open('GET', '/wheel_1?speed=' + wheel_1, false);
            request.send();
        }
        /* Функция отправки данных по изменении данных слайдера для колеса 2 */
        function ch_wheel_2() {
            // Значение слайдера колеса 2
            const wheel_2 = document.getElementById("inp_wheel_2").value * inv_data_wheel_2;
            console.log("wheel_2: " + wheel_2);

            /* Отправка GET запроса от клиента к серверу (микроконтроллеру) */
            request = new XMLHttpRequest();
            request.open('GET', '/wheel_2?speed=' + wheel_2, false);
            request.send();
        }
        /* Функция отправки данных по изменении данных слайдера для колеса 3 */
        function ch_wheel_3() {
            // Значение слайдера колеса 3
            const wheel_3 = document.getElementById("inp_wheel_3").value * inv_data_wheel_3;
            console.log("wheel_3: " + wheel_3);

            /* Отправка GET запроса от клиента к серверу (микроконтроллеру) */
            request = new XMLHttpRequest();
            request.open('GET', '/wheel_3?speed=' + wheel_3, false);
            request.send();
        }
        /* Функция отправки данных по изменении данных слайдера для колеса 4 */
        function ch_wheel_4() {
            // Значение слайдера колеса 4
            const wheel_4 = document.getElementById("inp_wheel_4").value * inv_data_wheel_4;
            console.log("wheel_4: " + wheel_4);
            /* Отправка GET запроса от клиента к серверу (микроконтроллеру) */
            request = new XMLHttpRequest();
            request.open('GET', '/wheel_4?speed=' + wheel_4, false);
            request.send();
        }
        const inp_slider_wh_1 = document.getElementById("inp_wheel_1");
        const out_slider_wh_1 = document.getElementById("out_wheel_1");
        // Функция для обновления значения и цвета фона
        function updateSpeedValWheel(inp, out, inv) {
            const inp_slider_wh = document.getElementById(inp);
            const out_slider_wh = document.getElementById(out);
            out_slider_wh.textContent = Number(inp_slider_wh.value) * Number(inv);
        }
        // Добавление обработчиков событий для каждого слайдера
        document
            .getElementById("inp_wheel_1")
            .addEventListener("input", function () {
                updateSpeedValWheel("inp_wheel_1", "out_wheel_1", inv_data_wheel_1);
            });
        document
            .getElementById("inp_wheel_2")
            .addEventListener("input", function () {
                updateSpeedValWheel("inp_wheel_2", "out_wheel_2", inv_data_wheel_2);
            });
        document
            .getElementById("inp_wheel_3")
            .addEventListener("input", function () {
                updateSpeedValWheel("inp_wheel_3", "out_wheel_3", inv_data_wheel_3);
            });
        document
            .getElementById("inp_wheel_4")
            .addEventListener("input", function () {
                updateSpeedValWheel("inp_wheel_4", "out_wheel_4", inv_data_wheel_4);
            });
        // Инициализация значений при загрузке страницы
        updateSpeedValWheel("inp_wheel_1", "out_wheel_1", inv_data_wheel_1);
        updateSpeedValWheel("inp_wheel_2", "out_wheel_2", inv_data_wheel_2);
        updateSpeedValWheel("inp_wheel_3", "out_wheel_3", inv_data_wheel_3);
        updateSpeedValWheel("inp_wheel_4", "out_wheel_4", inv_data_wheel_4);
        document
            .getElementById("confirm_data")
            .addEventListener("click", function () {
                const selects = document.querySelectorAll('.ch_wheel');
                const selectedValues = new Set();
                let isUnique = true;
                const conf_wheel = [];
                selects.forEach(select => {
                    const value = select.value;
                    conf_wheel.push(String(value));
                    if (selectedValues.has(value)) {
                        isUnique = false;
                    } else {
                        selectedValues.add(value);
                    }
                    console.log(conf_wheel[0]);
                    console.log(conf_wheel[1]);
                    console.log(conf_wheel[2]);
                    console.log(conf_wheel[3]);
                });
                if (isUnique) {
                    /* Отправка GET запроса от клиента к серверу (микроконтроллеру) */
                    request = new XMLHttpRequest();
                    request.open('GET', '/cfg_wheel?cfg=' + "&wh_1=" + conf_wheel[0] + "&wh_2=" + conf_wheel[1] + "&wh_3=" + conf_wheel[2] + "&wh_3=" + conf_wheel[3], false);
                    request.send();
                } else {
                    alert('Есть повторяющиеся значения!');
                }
            });
            document
            .getElementById("ch_wh_1")
            .addEventListener("click", function () {
                rev_data_wh_1("ch_wh_1");
            });
        document
            .getElementById("ch_wh_2")
            .addEventListener("click", function () { 
                rev_data_wh_2("ch_wh_2");
            });
        document
            .getElementById("ch_wh_3")
            .addEventListener("click", function () { 
                rev_data_wh_3("ch_wh_3");
            });
        document
            .getElementById("ch_wh_4")
            .addEventListener("click", function () {
                rev_data_wh_4("ch_wh_4");
            });
    </script>
</body>
</html>)=====";

#endif