#ifndef ARENATEAM_H
#define ARENATEAM_H

#include <QString>
#include <memory>
#include <vector>
#include "arenamember.h"


class ArenaTeam
{
public:
    ArenaTeam(std::shared_ptr<ArenaMember> pleb );
    void buyNewMember(ArenaMember &newpleb);

private:
    std::vector<std::shared_ptr<ArenaMember>> members;
    uint gold;
    QString name;

};

#endif // ARENATEAM_H
