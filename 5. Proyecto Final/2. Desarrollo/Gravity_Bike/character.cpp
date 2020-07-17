#include "character.h"

character::character()
{

    movie = new QMovie("../Gravity_Bike/sources/character/hittin_nbg.gif");

    connect(movie, SIGNAL(frameChanged(int)), this, SLOT(OnFrameChanged(int)));

    setMovie(movie);
    movie->start();
    setAttribute( Qt::WA_TranslucentBackground, true );

    //make corpus focusable
    setFocus(Qt::OtherFocusReason);



}

void character::OnFrameChanged(int /*frame*/)
{
    QPixmap pixmap = movie->currentPixmap();
    QMatrix rm;
    rm.rotate(60);
    pixmap = pixmap.transformed(rm);
    setPixmap(pixmap);


}
