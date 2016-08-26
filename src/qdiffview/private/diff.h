#pragma once

#include "dtl/variables.hpp"
#include <QStringList>

namespace qdiffview
{
struct Diff {
    int oldOffset;
    int newOffset;
    bool visible;
    dtl::edit_t type;
    QStringList lines;

    Diff(int oo, int no, dtl::edit_t t)
        : oldOffset(0)
        , newOffset(0)
        , visible(true)
        , type(t)
    {
        switch (t) {
        case dtl::SES_COMMON:
            this->oldOffset = oo;
            this->newOffset = no;
            this->visible = false;
            break;
        case dtl::SES_ADD:
            this->newOffset = no;
            break;
        case dtl::SES_DELETE:
            this->oldOffset = oo;
            break;
        }
    }
};
}
