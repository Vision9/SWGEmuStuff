/*
 *	server/zone/objects/tangible/terminal/characterbuilder/CharacterBuilderTerminal.h generated by engine3 IDL compiler 0.60
 */

#ifndef CHARACTERBUILDERTERMINAL_H_
#define CHARACTERBUILDERTERMINAL_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerCreature;

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace templates {

class SharedObjectTemplate;

} // namespace templates
} // namespace zone
} // namespace server

using namespace server::zone::templates;

#include "server/zone/objects/tangible/terminal/characterbuilder/CharacterBuilderMenuNode.h"

#include "server/zone/objects/tangible/terminal/Terminal.h"

#include "engine/lua/LuaObject.h"

#include "system/util/VectorMap.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {
namespace characterbuilder {

class CharacterBuilderTerminal : public Terminal {
public:
	CharacterBuilderTerminal();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void initializeTransientMembers();

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	void sendInitialChoices(PlayerCreature* player);

	void giveLanguages(PlayerCreature* player);

	void enhanceCharacter(PlayerCreature* player);

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	CharacterBuilderTerminal(DummyConstructorParameter* param);

	virtual ~CharacterBuilderTerminal();

	friend class CharacterBuilderTerminalHelper;
};

} // namespace characterbuilder
} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal::characterbuilder;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {
namespace characterbuilder {

class CharacterBuilderTerminalImplementation : public TerminalImplementation {
public:
	Reference<CharacterBuilderMenuNode* > rootNode;

	int performanceBuff;

	int medicalBuff;

	int performanceDuration;

	int medicalDuration;

	CharacterBuilderTerminalImplementation();

	CharacterBuilderTerminalImplementation(DummyConstructorParameter* param);

	void loadTemplateData(SharedObjectTemplate* templateData);

	void initializeTransientMembers();

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	void sendInitialChoices(PlayerCreature* player);

	void giveLanguages(PlayerCreature* player);

	void enhanceCharacter(PlayerCreature* player);

private:
	bool doEnhanceCharacter(unsigned int crc, PlayerCreature* player, int amount, int duration, int buffType, byte attribute);

public:
	CharacterBuilderTerminal* _this;

	operator const CharacterBuilderTerminal*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~CharacterBuilderTerminalImplementation();

	Object* clone();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const String& name);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class CharacterBuilderTerminal;
	friend class TransactionalObjectHandle<CharacterBuilderTerminalImplementation*>;
};

class CharacterBuilderTerminalAdapter : public TerminalAdapter {
public:
	CharacterBuilderTerminalAdapter(CharacterBuilderTerminalImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	void sendInitialChoices(PlayerCreature* player);

	void giveLanguages(PlayerCreature* player);

	void enhanceCharacter(PlayerCreature* player);

};

class CharacterBuilderTerminalHelper : public DistributedObjectClassHelper, public Singleton<CharacterBuilderTerminalHelper> {
	static CharacterBuilderTerminalHelper* staticInitializer;

public:
	CharacterBuilderTerminalHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<CharacterBuilderTerminalHelper>;
};

} // namespace characterbuilder
} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal::characterbuilder;

#endif /*CHARACTERBUILDERTERMINAL_H_*/
