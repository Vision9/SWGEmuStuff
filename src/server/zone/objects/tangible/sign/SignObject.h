/*
 *	server/zone/objects/tangible/sign/SignObject.h generated by engine3 IDL compiler 0.60
 */

#ifndef SIGNOBJECT_H_
#define SIGNOBJECT_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

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

#include "server/zone/objects/tangible/TangibleObject.h"

#include "engine/lua/LuaObject.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace sign {

class SignObject : public TangibleObject {
public:
	SignObject();

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	void sendSignNameTo(PlayerCreature* player);

	bool isSignObject();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	SignObject(DummyConstructorParameter* param);

	virtual ~SignObject();

	friend class SignObjectHelper;
};

} // namespace sign
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::sign;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace sign {

class SignObjectImplementation : public TangibleObjectImplementation {

public:
	SignObjectImplementation();

	SignObjectImplementation(DummyConstructorParameter* param);

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	void sendSignNameTo(PlayerCreature* player);

	bool isSignObject();

	SignObject* _this;

	operator const SignObject*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~SignObjectImplementation();

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

	friend class SignObject;
	friend class TransactionalObjectHandle<SignObjectImplementation*>;
};

class SignObjectAdapter : public TangibleObjectAdapter {
public:
	SignObjectAdapter(SignObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	void sendSignNameTo(PlayerCreature* player);

	bool isSignObject();

};

class SignObjectHelper : public DistributedObjectClassHelper, public Singleton<SignObjectHelper> {
	static SignObjectHelper* staticInitializer;

public:
	SignObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<SignObjectHelper>;
};

} // namespace sign
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::sign;

#endif /*SIGNOBJECT_H_*/
