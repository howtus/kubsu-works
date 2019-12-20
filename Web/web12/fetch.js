// Нажатие кнопки отправки в форме с ID = form
$("#form").onsubmit = async (e) => {
    // Запрещаем обновление страницы
    e.preventDefault();
    // Создаем объект данных формы
    // https://learn.javascript.ru/formdata
    var formData = new FormData();

    // Заполняем объект данных формы
    for (var i = 0; i < formInputs.length; i++) {
        // Добавляем все инпуты в formData().
        formData.append(formInputs[i].name, formInputs[i].value);
    }
    for (var i = 0; i < formTextAreas.length; i++) {
        // Добавляем все textareas в formData().
        formData.append(formTextAreas[i].name, formTextAreas[i].value);
    }

    // Отправляем запрос на сервер через fetch
    let response = await fetch("https://formcarry.com/s/XXXXXX", {
        method: "POST",
        headers: {
            "Accept": "application/json"
        },
        body: formData
    });

    // Если статус ok = true
    if (response.ok) {
        // Парсим ответ
        let result = await response.json();
        // Выводим ответ
        alert(result.title + "\n" + result.message);
    } else {
        alert("Ошибка!");
    }
};
