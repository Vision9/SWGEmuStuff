/*
 *	server/zone/objects/creature/aigroup/HerdGroup.h generated by engine3 IDL compiler 0.60
 */

#ifndef HERDGROUP_H_
#define HERDGROUP_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

#include "server/zone/objects/creature/aigroup/AiGroup.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace aigroup {

class HerdGroup : public AiGroup {
public:
	HerdGroup();

	bool isHerdGroup();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	HerdGroup(DummyConstructorParameter* param);

	virtual ~HerdGroup();

	friend class HerdGroupHelper;
};

} // namespace aigroup
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::aigroup;

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace aigroup {

class HerdGroupImplementation : public AiGroupImplementation {

public:
	HerdGroupImplementation();

	HerdGroupImplementation(DummyConstructorParameter* param);

	bool isHerdGroup();

	HerdGroup* _this;

	operator const HerdGroup*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~HerdGroupImplementation();

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

	friend class HerdGroup;
	friend class TransactionalObjectHandle<HerdGroupImplementation*>;
};

class HerdGroupAdapter : public AiGroupAdapter {
public:
	HerdGroupAdapter(HerdGroupImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	bool isHerdGroup();

};

class HerdGroupHelper : public DistributedObjectClassHelper, public Singleton<HerdGroupHelper> {
	static HerdGroupHelper* staticInitializer;

public:
	HerdGroupHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<HerdGroupHelper>;
};

} // namespace aigroup
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::aigroup;

#endif /*HERDGROUP_H_*/
