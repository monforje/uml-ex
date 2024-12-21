# Система доставки (симуляция "Самокат")

Данный проект представляет собой реализацию системы доставки на C++, вдохновленную сервисом "Самокат". Он включает функции взаимодействия с клиентами, управление продуктами, обработку заказов и отслеживание доставки.

## Возможности

### Роли пользователей

- **Клиент**:
  - Просматривать каталог продуктов и добавлять товары в корзину.
  - Оформлять заказы и производить оплату.
  - Отслеживать статус заказа и просматривать историю заказов.
  - Обновлять адрес доставки.

- **Сборщик**:
  - Назначать упаковки к заказам и собирать их для отправки.
  - Подтверждать готовность заказа к доставке.
  - Сообщать о проблемах с заказами.

- **Курьер**:
  - Начинать и завершать доставку.
  - Обновлять текущее местоположение и отменять доставку, если требуется.

- **Администратор**:
  - Управлять пользователями системы.
  - Генерировать отчеты о работе.

### Управление продуктами

- Продукты обладают следующими атрибутами:
  - **ID продукта**
  - **Название**
  - **Цена**
  - **Описание**
  - **Остаток на складе**

### Заказы

- Заказы проходят через следующие статусы:
  - **ASSEMBLY** (сборка)
  - **DELIVERING** (доставка)
  - **COMPLETED** (завершено)
  - **CANCELLED** (отменено)
- Поддерживаются следующие действия с заказами:
  - Подсчет общей стоимости.
  - Обновление статуса.
  - Отмена заказа.

### Оплата

- Реализованы два метода оплаты:
  - **Оплата картой**: Симуляция проверки карты.
  - **Оплата через СБП**: Симуляция проверки оплаты через банк.

### Возможности приложения

- Просмотр каталога продуктов.
- Управление корзиной.
- Отслеживание заказов.

### Система Даркстора

- Назначение заказов сборщикам.
- Уведомление курьеров о доставке.

## Пример работы

1. **Взаимодействие с клиентом**:
   - Клиент просматривает каталог продуктов.
   - Добавляет товары в корзину.
   - Оформляет заказ и оплачивает его.

2. **Сборка заказа**:
   - Сборщик собирает заказ.
   - Подтверждает его готовность к доставке.

3. **Доставка**:
   - Курьер начинает доставку и обновляет местоположение.
   - Завершает доставку.

4. **Администрирование**:
   - Администратор генерирует отчет.

## Возможные улучшения

- Добавление базы данных для сохранения продуктов и заказов.
- Интеграция GPS для отслеживания местоположения курьеров в реальном времени.
- Улучшение проверки оплаты.
- Создание веб-интерфейса или графического интерфейса для удобства пользователей.

