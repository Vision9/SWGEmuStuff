/*
 *	server/zone/objects/staticobject/StaticObject.h generated by engine3 IDL compiler 0.60
 */

#ifndef STATICOBJECT_H_
#define STATICOBJECT_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

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

#include "engine/lua/LuaObject.h"

#include "server/zone/objects/scene/SceneObject.h"

namespace server {
namespace zone {
namespace objects {
namespace staticobject {

class StaticObject : public SceneObject {
public:
	StaticObject();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void sendBaselinesTo(SceneObject* player);

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	StaticObject(DummyConstructorParameter* param);

	virtual ~StaticObject();

	friend class StaticObjectHelper;
};

} // namespace staticobject
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::staticobject;

namespace server {
namespace zone {
namespace objects {
namespace staticobject {

class StaticObjectImplementation : public SceneObjectImplementation {

public:
	StaticObjectImplementation();

	StaticObjectImplementation(DummyConstructorParameter* param);

	void loadTemplateData(SharedObjectTemplate* templateData);

	void sendBaselinesTo(SceneObject* player);

	StaticObject* _this;

	operator const StaticObject*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~StaticObjectImplementation();

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

	friend class StaticObject;
	friend class TransactionalObjectHandle<StaticObjectImplementation*>;
};

class StaticObjectAdapter : public SceneObjectAdapter {
public:
	StaticObjectAdapter(StaticObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void sendBaselinesTo(SceneObject* player);

};

class StaticObjectHelper : public DistributedObjectClassHelper, public Singleton<StaticObjectHelper> {
	static StaticObjectHelper* staticInitializer;

public:
	StaticObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<StaticObjectHelper>;
};

} // namespace staticobject
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::staticobject;

#endif /*STATICOBJECT_H_*/
