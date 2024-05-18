/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <KLocalizedSpinBox>

#include <QApplication>
#include <QSpinBox>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QSpinBox spinBox;
    KLocalizedSpinBox::setSuffix(&spinBox, ki18np("cake", "cakes"));
    spinBox.show();

    return app.exec();
}
