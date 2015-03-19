/*
 * Copyright 2014  Martin Gräßlin <mgraesslin@kde.org>
 * Copyright 2014  Hugo Pereira Da Costa <hugo.pereira@free.fr>
 * Copyright 2015  Kenneth Vermette <vermette@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License or (at your option) version 3 or any later version
 * accepted by the membership of KDE e.V. (or its successor approved
 * by the membership of KDE e.V.), which shall act as a proxy
 * defined in Section 14 of version 3 of the license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "breezebutton.h"

#include <KDecoration2/DecoratedClient>
#include <KColorUtils>
#include <KColorScheme>

#include <QPainter>

namespace Breeze
{

    //__________________________________________________________________
    Button::Button(KDecoration2::DecorationButtonType type, Decoration* decoration, QObject* parent)
        : DecorationButton(type, decoration, parent)
        , m_animation( new QPropertyAnimation( this ) )
    {

        // setup animation
        m_animation->setStartValue( 0 );
        m_animation->setEndValue( 1.0 );
        m_animation->setTargetObject( this );
        m_animation->setPropertyName( "opacity" );
        m_animation->setEasingCurve( QEasingCurve::InOutQuad );

        // setup default geometry
        const int height = decoration->buttonHeight();
        setGeometry(QRect(0, 0, height, height));

        // connect hover state changed
        connect( this, &KDecoration2::DecorationButton::hoveredChanged, this, &Button::updateAnimationState );

    }

    //__________________________________________________________________
    Button::Button(QObject *parent, const QVariantList &args)
        : DecorationButton(args.at(0).value<KDecoration2::DecorationButtonType>(), args.at(1).value<Decoration*>(), parent)
        , m_flag(FlagStandalone)
        , m_animation( new QPropertyAnimation( this ) )
    {}

    //__________________________________________________________________
    Button *Button::create(KDecoration2::DecorationButtonType type, KDecoration2::Decoration *decoration, QObject *parent)
    {
        if (auto d = qobject_cast<Decoration*>(decoration))
        {
            Button *b = new Button(type, d, parent);
            if (type == KDecoration2::DecorationButtonType::Menu)
            {
                QObject::connect(d->client().data(), &KDecoration2::DecoratedClient::iconChanged, b, [b]() { b->update(); });
            }
            return b;
        }
        return nullptr;
    }

    //__________________________________________________________________
    Button::~Button() = default;

    //__________________________________________________________________
    void Button::paint(QPainter *painter, const QRect &repaintRegion)
    {
        Q_UNUSED(repaintRegion)

        if (!decoration()) return;

        painter->save();

        // translate from offset
        if( m_flag == FlagFirstInList ) painter->translate( m_offset );
        else painter->translate( 0, m_offset.y() );

        if (type() == KDecoration2::DecorationButtonType::Menu)
        {

            const QSizeF iconSize( size().width()-m_offset.x(), size().height()-m_offset.y() );
            const QRectF iconRect( geometry().topLeft(), iconSize );
            const QPixmap pixmap = decoration()->client().data()->icon().pixmap( iconSize.toSize());
            painter->drawPixmap(iconRect.center() - QPoint(pixmap.width()/2, pixmap.height()/2), pixmap);

        } else {

            drawIcon( painter );

        }

        painter->restore();

    }

    //__________________________________________________________________
    QColor Button::iconColor( void ) const {
        auto d = qobject_cast<Decoration*>( decoration() );

        if( !d ) {
          return QColor();
        }

        if (isChecked() && type() != KDecoration2::DecorationButtonType::Maximize) {
          return d->titleBarColor();
        }

        if( m_animation->state() == QPropertyAnimation::Running ) {
            return KColorUtils::mix( d->fontColor(), buttonColor().darker(buttonColor().lightness() > 192 ? 190 : 10), curvedOpacity() );
        }
        else if (isHovered()){
            return buttonColor().darker(buttonColor().lightness() > 192 ? 190 : 10);
        }
        else if (d->client().data()->isActive()) { // Active Windows
            //if (type() == KDecoration2::DecorationButtonType::Close)
            //    return d->titleBarColor();
            //else
                return d->fontColor();
        }
        else { // Inactive Windows
           return d->fontColor().darker(d->fontColor().value() > 128 ? 150 : 50);
        }
    }

    //__________________________________________________________________
    QColor Button::ringColor( void ) const {
        auto d = qobject_cast<Decoration*>( decoration() );

        if( !d ) {
          return QColor();
        }

        if (isChecked() && type() != KDecoration2::DecorationButtonType::Maximize) {
          return d->fontColor();
        }

        if( m_animation->state() == QPropertyAnimation::Running && d->client().data()->isActive() ) {
            return KColorUtils::mix( buttonColor(), buttonColor().darker(d->titleBarColor().value() > 128 ? 120 : 80), m_opacity );
        }
        else if( m_animation->state() == QPropertyAnimation::Running ) {
            return KColorUtils::mix ( d->titleBarHighlightColor(), buttonColor().darker(d->titleBarColor().value() > 128 ? 120 : 80), m_opacity );
        }
        else if (isHovered()){
            return buttonColor().darker(d->titleBarColor().value() > 128 ? 120 : 80);
        }
        else if (d->client().data()->isActive()) { // Active Windows
            //if (type() == KDecoration2::DecorationButtonType::Close)
            //  return d->fontColor();
            //else
              return buttonColor();
        }
        else { // Inactive Windows
            //if (type() == KDecoration2::DecorationButtonType::Close)
            //    return buttonColor();
            //else
                return d->titleBarHighlightColor();
        }
    }

    //__________________________________________________________________
    QColor Button::backgroundColor( void ) const {
        auto d = qobject_cast<Decoration*>( decoration() );

        if( !d ) {
          return QColor();
        }

        if (isChecked() && type() != KDecoration2::DecorationButtonType::Maximize) {
          return d->fontColor().darker(d->fontColor().value() > 128 ? 120 : 80);
        }

        if( m_animation->state() == QPropertyAnimation::Running ) {
            return KColorUtils::mix( d->titleBarColor(), buttonColor(), curvedOpacity() );
        }
        else if (isHovered()){
            return buttonColor();
        }
        else if (d->client().data()->isActive()) { // Active Windows
            //if (type() == KDecoration2::DecorationButtonType::Close)
            //  return d->fontColor();
            //else
              return d->titleBarColor();
        }
        else { // Inactive Windows
            return d->titleBarColor();
        }
    }

    //__________________________________________________________________
    qreal Button::ringRadius( void ) const {
        if( m_animation->state() == QPropertyAnimation::Running ) {
            return 4.5 + ((m_opacity) * 3.5);
        }
        else if (isHovered()){
            return 8;
        }
        else {
            return 4.5;
        }
    }

    //__________________________________________________________________
    qreal Button::curvedOpacity( void ) const {
      return m_opacity > .5 ? ((m_opacity - 0.5) * 2) : 0;
    }


    //__________________________________________________________________
    QColor Button::buttonColor( void ) const {
        KColorScheme colourGroup(QPalette::Active);

        switch( type() ) {
            case KDecoration2::DecorationButtonType::Close:
                return colourGroup.foreground(KColorScheme::ForegroundRole::NegativeText).color();
            case KDecoration2::DecorationButtonType::Maximize:
                return colourGroup.foreground(KColorScheme::ForegroundRole::PositiveText).color();
            case KDecoration2::DecorationButtonType::Minimize:
                return colourGroup.foreground(KColorScheme::ForegroundRole::NeutralText).color();
            case KDecoration2::DecorationButtonType::OnAllDesktops:
            case KDecoration2::DecorationButtonType::Shade:
            case KDecoration2::DecorationButtonType::KeepBelow:
            case KDecoration2::DecorationButtonType::KeepAbove:
            case KDecoration2::DecorationButtonType::ApplicationMenu:
            case KDecoration2::DecorationButtonType::ContextHelp:
            default:
                return colourGroup.decoration(KColorScheme::DecorationRole::FocusColor).color();
        }

        return QColor();
    }


    //__________________________________________________________________
    void Button::updateAnimationState( bool hovered )
    {

        auto d = qobject_cast<Decoration*>(decoration());
        if( !(d && d->internalSettings()->animationsEnabled() ) ) return;

        m_animation->setDirection( hovered ? QPropertyAnimation::Forward : QPropertyAnimation::Backward );
        if( m_animation->state() != QPropertyAnimation::Running ) m_animation->start();

    }

    //__________________________________________________________________
    void Button::drawIcon( QPainter *painter ) const
    {
        /*
         * Parent Deco
         */
        auto d = qobject_cast<Decoration*>( decoration() );


        /*
         * Common Values
         */
        const qreal width( geometry().width() - m_offset.x() );
        //const qreal penWidth( 2.3 );
        const QColor ringColor( this->ringColor() );
        const QColor backgroundColor( this->backgroundColor() );


        /*
         * Painter Setup
         */
        painter->setRenderHints( QPainter::Antialiasing );
        painter->translate( geometry().topLeft() );
        painter->scale( width/40, width/40 );
        painter->translate( 1, 1 );


        /*
         * Button Chrome
         */
        // Outline
        painter->setPen( Qt::NoPen );
        painter->setBrush( d->titleBarOutlineColor() );
        painter->drawEllipse( QRectF( 0, 0, 36, 36 ) );

        // Ring
        painter->setBrush( ringColor.isValid() ? ringColor : d->titleBarHighlightColor() );
        painter->drawEllipse( QRectF( 1, 1, 34, 34 ) );


        // Button Background
        painter->setBrush( backgroundColor.isValid() ? backgroundColor : d->titleBarColor() );
        painter->drawEllipse( QRectF( ringRadius(), ringRadius(), 36 - (ringRadius() * 2), 36 - (ringRadius() * 2) ) );

        // Draw Glyph outline and fill
        drawGlyph(painter, true);
        drawGlyph(painter, false);
    }

    //__________________________________________________________________
    void Button::drawGlyph( QPainter *painter, bool outlineMode) const
    {
        /*
         * Common Values
         */
        const QColor iconColor( outlineMode ?
          this->backgroundColor().darker(this->iconColor().value() > this->backgroundColor().value() ? 130 : 90) :
          this->iconColor()
        );
        const qreal penWidth( outlineMode ? 4.3 : 2.3 );


        if( !iconColor.isValid() ) {
          return;
        }


        // Pen Setup
        QPen pen( iconColor );
        pen.setCapStyle( outlineMode ? Qt::SquareCap : Qt::SquareCap );
        pen.setJoinStyle( outlineMode ? Qt::RoundJoin : Qt::MiterJoin );
        pen.setWidthF( penWidth );

        // Painter Setup
        painter->setPen( pen );
        painter->setBrush( Qt::NoBrush );


        /*
        * Glyph Painting
        */
        switch( type() ) {
            case KDecoration2::DecorationButtonType::Close: {
                painter->drawLine( QPointF( 11, 11 ), QPointF( 25 , 25 ) );
                painter->drawLine( 11, 25, 25, 11 );
                break;
            }


            case KDecoration2::DecorationButtonType::Maximize: {
                if( isChecked() ) {
                    painter->drawPolyline( QPolygonF()
                        << QPointF( 18, 11  ) // top mid
                        << QPointF( 25, 18  ) // right mid
                        << QPointF( 18 , 25  ) // bottom mid
                        << QPointF( 11 , 18  ) // left mid
                        << QPointF( 18 , 11  )); // top mid
                }

                else {
                    painter->drawPolyline( QPolygonF()
                        << QPointF( 11, 21 )
                        << QPointF( 18 , 14 )
                        << QPointF( 25 , 21 ));
                }
                break;
            }


            case KDecoration2::DecorationButtonType::Minimize: {
                painter->drawPolyline( QPolygonF()
                  << QPointF( 11, 15 )
                  << QPointF( 18 , 22 )
                  << QPointF( 25 , 15 ));
                break;
            }


            case KDecoration2::DecorationButtonType::OnAllDesktops: {
                if (!outlineMode) {
                    painter->setPen( Qt::NoPen );
                    painter->setBrush( iconColor );
                }
                else {
                    pen.setWidthF( 2.0 );
                    painter->setPen( pen );
                }

                if( isChecked() ) {
                    painter->drawEllipse( QRectF( 16, 16, 4, 4 ) );
                }
                else {
                    painter->drawPolygon( QPolygonF()
                      << QPointF( 21, 9 )
                      << QPointF( 21, 13 )
                      << QPointF( 17, 15 )
                      << QPointF( 13, 15 )
                      << QPointF( 16, 18 )
                      << QPointF( 11, 25 )
                      << QPointF( 18, 20 )
                      << QPointF( 21, 23 )
                      << QPointF( 21, 19 )
                      << QPointF( 23, 15 )
                      << QPointF( 27, 15 )
                      << QPointF( 21, 9 ));
                }
                break;
            }


            case KDecoration2::DecorationButtonType::Shade: {
                if (isChecked()) {
                    painter->drawLine( 11, 24, 25, 24 );
                    painter->drawPolyline( QPolygonF()
                      << QPointF( 11, 13 )
                      << QPointF( 18 , 20 )
                      << QPointF( 25 , 13 ));
                }
                else {
                    painter->drawLine( 11, 12, 25, 12 );
                    painter->drawPolyline( QPolygonF()
                      << QPointF( 11, 25 )
                      << QPointF( 18 , 18 )
                      << QPointF( 25 , 25 ));
                }
                break;
            }


            case KDecoration2::DecorationButtonType::KeepBelow: {
                painter->drawPolyline( QPolygonF()
                  << QPointF( 11, 13 )
                  << QPointF( 18 , 20 )
                  << QPointF( 25 , 13 ));

                painter->drawPolyline( QPolygonF()
                  << QPointF( 11, 19 )
                  << QPointF( 18 , 26 )
                  << QPointF( 25 , 19 ));
                break;
            }

            //Q_DECL_CONSTEXPR QRectF(qreal left, qreal top, qreal width, qreal height);
            case KDecoration2::DecorationButtonType::KeepAbove: {
                painter->drawPolyline( QPolygonF()
                  << QPointF( 11, 19 )
                  << QPointF( 18 , 12 )
                  << QPointF( 25 , 19 ));

                painter->drawPolyline( QPolygonF()
                  << QPointF( 11, 25 )
                  << QPointF( 18 , 18 )
                  << QPointF( 25 , 25 ));
                break;
            }


            case KDecoration2::DecorationButtonType::ApplicationMenu: {
                if (!outlineMode) {
                    painter->setPen( Qt::NoPen );
                    painter->setBrush( iconColor );
                }
                else {
                    pen.setWidthF( 2.0 );
                    painter->setPen( pen );
                }

                painter->drawEllipse( QRectF( 16, 10, 4, 4 ) );
                painter->drawEllipse( QRectF( 16, 16, 4, 4 ) );
                painter->drawEllipse( QRectF( 16, 22, 4, 4 ) );

                break;
            }


            case KDecoration2::DecorationButtonType::ContextHelp: {
                QPainterPath path;
                path.moveTo( 13, 16 );
                path.arcTo( QRectF( 13, 10, 10, 6 ), 180, -180 );
                path.cubicTo( QPointF(25, 19), QPointF( 18, 15 ), QPointF( 18, 23 ) );
                painter->drawPath( path );

                painter->drawEllipse( QRectF( 18, 25, 1, 1 ) );
                break;
            }

            default:
                if (!outlineMode) {
                    painter->setPen( Qt::NoPen );
                    painter->setBrush( iconColor );
                }
                else {
                    pen.setWidthF( 2.0 );
                    painter->setPen( pen );
                }

                painter->drawEllipse( QRectF( 13, 13, 10, 10 ) );
        }

    }

} // namespace
