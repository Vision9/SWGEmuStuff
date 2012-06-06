/*
 *	server/zone/objects/creature/buffs/PowerBoostBuff.cpp generated by engine3 IDL compiler 0.60
 */

#include "PowerBoostBuff.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/creature/buffs/PowerBoostBuffDurationEvent.h"

/*
 *	PowerBoostBuffStub
 */

enum {RPC_INITIALIZETRANSIENTMEMBERS__ = 6,RPC_ACTIVATE__BOOL_,RPC_DEACTIVATE__BOOL_,RPC_DOHEALTHANDACTIONTICK__BOOL_,RPC_DOMINDTICK__BOOL_,RPC_CLEARBUFFEVENT__};

PowerBoostBuff::PowerBoostBuff(CreatureObject* creo, const String& name, unsigned int buffCRC, int value, int duration) : Buff(DummyConstructorParameter::instance()) {
	PowerBoostBuffImplementation* _implementation = new PowerBoostBuffImplementation(creo, name, buffCRC, value, duration);
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("PowerBoostBuff");
}

PowerBoostBuff::PowerBoostBuff(DummyConstructorParameter* param) : Buff(param) {
	_setClassName("PowerBoostBuff");
}

PowerBoostBuff::~PowerBoostBuff() {
}



void PowerBoostBuff::initializeTransientMembers() {
	PowerBoostBuffImplementation* _implementation = static_cast<PowerBoostBuffImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

void PowerBoostBuff::activate(bool applyModifiers) {
	PowerBoostBuffImplementation* _implementation = static_cast<PowerBoostBuffImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ACTIVATE__BOOL_);
		method.addBooleanParameter(applyModifiers);

		method.executeWithVoidReturn();
	} else
		_implementation->activate(applyModifiers);
}

void PowerBoostBuff::deactivate(bool removeModifiers) {
	PowerBoostBuffImplementation* _implementation = static_cast<PowerBoostBuffImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DEACTIVATE__BOOL_);
		method.addBooleanParameter(removeModifiers);

		method.executeWithVoidReturn();
	} else
		_implementation->deactivate(removeModifiers);
}

void PowerBoostBuff::doHealthAndActionTick(bool up) {
	PowerBoostBuffImplementation* _implementation = static_cast<PowerBoostBuffImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DOHEALTHANDACTIONTICK__BOOL_);
		method.addBooleanParameter(up);

		method.executeWithVoidReturn();
	} else
		_implementation->doHealthAndActionTick(up);
}

void PowerBoostBuff::doMindTick(bool up) {
	PowerBoostBuffImplementation* _implementation = static_cast<PowerBoostBuffImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DOMINDTICK__BOOL_);
		method.addBooleanParameter(up);

		method.executeWithVoidReturn();
	} else
		_implementation->doMindTick(up);
}

void PowerBoostBuff::clearBuffEvent() {
	PowerBoostBuffImplementation* _implementation = static_cast<PowerBoostBuffImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CLEARBUFFEVENT__);

		method.executeWithVoidReturn();
	} else
		_implementation->clearBuffEvent();
}

DistributedObjectServant* PowerBoostBuff::_getImplementation() {

	_updated = true;
	return _impl;
}

void PowerBoostBuff::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	PowerBoostBuffImplementation
 */

PowerBoostBuffImplementation::PowerBoostBuffImplementation(DummyConstructorParameter* param) : BuffImplementation(param) {
	_initializeImplementation();
}


PowerBoostBuffImplementation::~PowerBoostBuffImplementation() {
}


void PowerBoostBuffImplementation::finalize() {
}

void PowerBoostBuffImplementation::_initializeImplementation() {
	_setClassHelper(PowerBoostBuffHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void PowerBoostBuffImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<PowerBoostBuff*>(stub);
	BuffImplementation::_setStub(stub);
}

DistributedObjectStub* PowerBoostBuffImplementation::_getStub() {
	return _this.get();
}

PowerBoostBuffImplementation::operator const PowerBoostBuff*() {
	return _this.get();
}

void PowerBoostBuffImplementation::lock(bool doLock) {
	_this.get()->lock(doLock);
}

void PowerBoostBuffImplementation::lock(ManagedObject* obj) {
	_this.get()->lock(obj);
}

void PowerBoostBuffImplementation::rlock(bool doLock) {
	_this.get()->rlock(doLock);
}

void PowerBoostBuffImplementation::wlock(bool doLock) {
	_this.get()->wlock(doLock);
}

void PowerBoostBuffImplementation::wlock(ManagedObject* obj) {
	_this.get()->wlock(obj);
}

void PowerBoostBuffImplementation::unlock(bool doLock) {
	_this.get()->unlock(doLock);
}

void PowerBoostBuffImplementation::runlock(bool doLock) {
	_this.get()->runlock(doLock);
}

void PowerBoostBuffImplementation::_serializationHelperMethod() {
	BuffImplementation::_serializationHelperMethod();

	_setClassName("PowerBoostBuff");

}

void PowerBoostBuffImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(PowerBoostBuffImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool PowerBoostBuffImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (BuffImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "PowerBoostBuff.pbBonus") {
		TypeInfo<int >::parseFromBinaryStream(&pbBonus, stream);
		return true;
	}

	if (_name == "PowerBoostBuff.pbTick") {
		TypeInfo<int >::parseFromBinaryStream(&pbTick, stream);
		return true;
	}

	if (_name == "PowerBoostBuff.time") {
		TypeInfo<int >::parseFromBinaryStream(&time, stream);
		return true;
	}

	if (_name == "PowerBoostBuff.counter") {
		TypeInfo<int >::parseFromBinaryStream(&counter, stream);
		return true;
	}

	if (_name == "PowerBoostBuff.nextTickTime") {
		TypeInfo<Time >::parseFromBinaryStream(&nextTickTime, stream);
		return true;
	}


	return false;
}

void PowerBoostBuffImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = PowerBoostBuffImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int PowerBoostBuffImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = BuffImplementation::writeObjectMembers(stream);

	String _name;
	int _offset;
	uint32 _totalSize;
	_name = "PowerBoostBuff.pbBonus";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<int >::toBinaryStream(&pbBonus, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "PowerBoostBuff.pbTick";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<int >::toBinaryStream(&pbTick, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "PowerBoostBuff.time";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<int >::toBinaryStream(&time, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "PowerBoostBuff.counter";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<int >::toBinaryStream(&counter, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "PowerBoostBuff.nextTickTime";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<Time >::toBinaryStream(&nextTickTime, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);


	return _count + 5;
}

PowerBoostBuffImplementation::PowerBoostBuffImplementation(CreatureObject* creo, const String& name, unsigned int buffCRC, int value, int duration) : BuffImplementation(creo, buffCRC, duration, BuffType::SKILL) {
	_initializeImplementation();
	// server/zone/objects/creature/buffs/PowerBoostBuff.idl():  		super.buffName = name;
	BuffImplementation::buffName = name;
	// server/zone/objects/creature/buffs/PowerBoostBuff.idl():  		pbBonus = value;
	pbBonus = value;
	// server/zone/objects/creature/buffs/PowerBoostBuff.idl():  		pbTick = value/20;
	pbTick = value / 20;
	// server/zone/objects/creature/buffs/PowerBoostBuff.idl():  		time = duration * 1000;
	time = duration * 1000;
	// server/zone/objects/creature/buffs/PowerBoostBuff.idl():  		counter = 0;
	counter = 0;
}

/*
 *	PowerBoostBuffAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


PowerBoostBuffAdapter::PowerBoostBuffAdapter(PowerBoostBuff* obj) : BuffAdapter(obj) {
}

void PowerBoostBuffAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		{
			initializeTransientMembers();
		}
		break;
	case RPC_ACTIVATE__BOOL_:
		{
			activate(inv->getBooleanParameter());
		}
		break;
	case RPC_DEACTIVATE__BOOL_:
		{
			deactivate(inv->getBooleanParameter());
		}
		break;
	case RPC_DOHEALTHANDACTIONTICK__BOOL_:
		{
			doHealthAndActionTick(inv->getBooleanParameter());
		}
		break;
	case RPC_DOMINDTICK__BOOL_:
		{
			doMindTick(inv->getBooleanParameter());
		}
		break;
	case RPC_CLEARBUFFEVENT__:
		{
			clearBuffEvent();
		}
		break;
	default:
		throw Exception("Method does not exists");
	}
}

void PowerBoostBuffAdapter::initializeTransientMembers() {
	(static_cast<PowerBoostBuff*>(stub))->initializeTransientMembers();
}

void PowerBoostBuffAdapter::activate(bool applyModifiers) {
	(static_cast<PowerBoostBuff*>(stub))->activate(applyModifiers);
}

void PowerBoostBuffAdapter::deactivate(bool removeModifiers) {
	(static_cast<PowerBoostBuff*>(stub))->deactivate(removeModifiers);
}

void PowerBoostBuffAdapter::doHealthAndActionTick(bool up) {
	(static_cast<PowerBoostBuff*>(stub))->doHealthAndActionTick(up);
}

void PowerBoostBuffAdapter::doMindTick(bool up) {
	(static_cast<PowerBoostBuff*>(stub))->doMindTick(up);
}

void PowerBoostBuffAdapter::clearBuffEvent() {
	(static_cast<PowerBoostBuff*>(stub))->clearBuffEvent();
}

/*
 *	PowerBoostBuffHelper
 */

PowerBoostBuffHelper* PowerBoostBuffHelper::staticInitializer = PowerBoostBuffHelper::instance();

PowerBoostBuffHelper::PowerBoostBuffHelper() {
	className = "PowerBoostBuff";

	Core::getObjectBroker()->registerClass(className, this);
}

void PowerBoostBuffHelper::finalizeHelper() {
	PowerBoostBuffHelper::finalize();
}

DistributedObject* PowerBoostBuffHelper::instantiateObject() {
	return new PowerBoostBuff(DummyConstructorParameter::instance());
}

DistributedObjectServant* PowerBoostBuffHelper::instantiateServant() {
	return new PowerBoostBuffImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* PowerBoostBuffHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new PowerBoostBuffAdapter(static_cast<PowerBoostBuff*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

