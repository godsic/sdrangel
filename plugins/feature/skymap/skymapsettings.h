///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2012 maintech GmbH, Otto-Hahn-Str. 15, 97204 Hoechberg, Germany //
// written by Christian Daniel                                                   //
// Copyright (C) 2015-2020, 2022 Edouard Griffiths, F4EXB <f4exb06@gmail.com>    //
// Copyright (C) 2020-2024 Jon Beniston, M7RCE <jon@beniston.com>                //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
// (at your option) any later version.                                           //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#ifndef INCLUDE_FEATURE_SKYMAPSETTINGS_H_
#define INCLUDE_FEATURE_SKYMAPSETTINGS_H_

#include <QByteArray>
#include <QString>
#include <QHash>

class Serializable;

struct SkyMapSettings
{
    QString m_map;                      //!< "WWT", "ESASky" or "Aladin"
    bool m_displayNames;
    bool m_displayConstellations;
    bool m_displayReticle;
    bool m_displayGrid;
    bool m_displayAntennaFoV;
    QString m_background;
    QString m_projection;
    QString m_source;                   //!< Plugin to get target coords from
    bool m_track;                       //!< Track source
    float m_hpbw;                       //!< Antenna HPBW
    float m_latitude;                   //!< Antenna position
    float m_longitude;
    float m_altitude;
    bool m_useMyPosition;
    QHash<QString, QVariant> m_wwtSettings; //!< WWT specific settings

    QString m_title;
    quint32 m_rgbColor;
    bool m_useReverseAPI;
    QString m_reverseAPIAddress;
    uint16_t m_reverseAPIPort;
    uint16_t m_reverseAPIFeatureSetIndex;
    uint16_t m_reverseAPIFeatureIndex;
    Serializable *m_rollupState;
    int m_workspaceIndex;
    QByteArray m_geometryBytes;

    SkyMapSettings();
    ~SkyMapSettings();
    void resetToDefaults();
    QByteArray serialize() const;
    bool deserialize(const QByteArray& data);
    void setRollupState(Serializable *rollupState) { m_rollupState = rollupState; }
    void applySettings(const QStringList& settingsKeys, const SkyMapSettings& settings);
    QString getDebugString(const QStringList& settingsKeys, bool force=false) const;

    static const QStringList m_pipeURIs;

};

#endif // INCLUDE_FEATURE_SKYMAPSETTINGS_H_

