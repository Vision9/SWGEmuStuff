/*
 *	server/zone/objects/tangible/terminal/city/CityVoteTerminal.h generated by engine3 IDL compiler 0.60
 */

#ifndef CITYVOTETERMINAL_H_
#define CITYVOTETERMINAL_H_

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
namespace packets {
namespace object {

class ObjectMenuResponse;

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace objects {
namespace building {
namespace city {

class CityHallObject;

} // namespace city
} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building::city;

#include "server/zone/objects/tangible/terminal/Terminal.h"

#include "engine/lua/LuaObject.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {
namespace city {

class CityVoteTerminal : public Terminal {
public:
	CityVoteTerminal();

	void initializeTransientMembers();

	void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, PlayerCreature* player);

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	bool isCityVoteTerminal();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	CityVoteTerminal(DummyConstructorParameter* param);

	virtual ~CityVoteTerminal();

	friend class CityVoteTerminalHelper;
};

} // namespace city
} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal::city;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {
namespace city {

class CityVoteTerminalImplementation : public TerminalImplementation {

public:
	CityVoteTerminalImplementation();

	CityVoteTerminalImplementation(DummyConstructorParameter* param);

	void initializeTransientMembers();

	void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, PlayerCreature* player);

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	bool isCityVoteTerminal();

	CityVoteTerminal* _this;

	operator const CityVoteTerminal*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~CityVoteTerminalImplementation();

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

	friend class CityVoteTerminal;
	friend class TransactionalObjectHandle<CityVoteTerminalImplementation*>;
};

class CityVoteTerminalAdapter : public TerminalAdapter {
public:
	CityVoteTerminalAdapter(CityVoteTerminalImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, PlayerCreature* player);

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	bool isCityVoteTerminal();

};

class CityVoteTerminalHelper : public DistributedObjectClassHelper, public Singleton<CityVoteTerminalHelper> {
	static CityVoteTerminalHelper* staticInitializer;

public:
	CityVoteTerminalHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<CityVoteTerminalHelper>;
};

} // namespace city
} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal::city;

#endif /*CITYVOTETERMINAL_H_*/
