/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KLOCALIZEDSPINBOX
#define KLOCALIZEDSPINBOX

#include "klocalizedstring.h"

#include <type_traits>

class QSpinBox;

/** Localization helpers for Qt spin box widgets.
 *  @since 6.3
 */
namespace KLocalizedSpinBox
{
/**
 * Sets the suffix string of @p spinBox to the plural form of @p suffix based on the current value.
 *
 * @code
 * QSpinBox box;
 * KLocalizedSpinBox::setSuffix(&box, ki18np("cake", "cakes"));
 * @endcode
 *
 * @since 6.3
 */
template<typename T>
inline void setSuffix(T *spinBox, const KLocalizedString &suffix)
{
    static_assert(std::is_base_of_v<QSpinBox, T>, "First argument must be a QSpinBox instance!");
    const auto updateSuffix = [spinBox, suffix]() {
        if (!suffix.isEmpty()) {
            spinBox->setSuffix(suffix.subs(spinBox->value()).toString());
        } else {
            spinBox->setSuffix({});
        }
    };
    updateSuffix();
    QObject::connect(spinBox, &T::valueChanged, spinBox, updateSuffix);
}
}

#endif
