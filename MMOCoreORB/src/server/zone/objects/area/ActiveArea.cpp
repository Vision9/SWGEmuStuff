/*
 *	server/zone/objects/area/ActiveArea.cpp generated by engine3 IDL compiler 0.60
 */

#include "ActiveArea.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/creature/CreatureObject.h"

/*
 *	ActiveAreaStub
 */

enum {RPC_SENDTO__SCENEOBJECT_BOOL_ = 6,RPC_ENQUEUEENTEREVENT__SCENEOBJECT_,RPC_ENQUEUEEXITEVENT__SCENEOBJECT_,RPC_NOTIFYENTER__SCENEOBJECT_,RPC_NOTIFYEXIT__SCENEOBJECT_,RPC_ISACTIVEAREA__,RPC_ISREGION__,RPC_ISCITYREGION__,RPC_ISNOBUILDAREA__,RPC_CONTAINSPOINT__FLOAT_FLOAT_,RPC_GETRADIUS2__,RPC_SETNOBUILDAREA__BOOL_,RPC_SETMUNICIPALZONE__BOOL_,RPC_SETRADIUS__FLOAT_,RPC_ISCAMPAREA__,RPC_SETNOSPAWNAREA__BOOL_,RPC_ISNOSPAWNAREA__,RPC_ISMUNICIPALZONE__,RPC_GETCELLOBJECTID__,RPC_SETCELLOBJECTID__LONG_};

ActiveArea::ActiveArea() : SceneObject(DummyConstructorParameter::instance()) {
	ActiveAreaImplementation* _implementation = new ActiveAreaImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("ActiveArea");
}

ActiveArea::ActiveArea(DummyConstructorParameter* param) : SceneObject(param) {
	_setClassName("ActiveArea");
}

ActiveArea::~ActiveArea() {
}



void ActiveArea::sendTo(SceneObject* player, bool doClose) {
	ActiveAreaImplementation* _implementation = static_cast<ActiveAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDTO__SCENEOBJECT_BOOL_);
		method.addObjectParameter(player);
		method.addBooleanParameter(doClose);

		method.executeWithVoidReturn();
	} else
		_implementation->sendTo(player, doClose);
}

void ActiveArea::enqueueEnterEvent(SceneObject* obj) {
	ActiveAreaImplementation* _implementation = static_cast<ActiveAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ENQUEUEENTEREVENT__SCENEOBJECT_);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else
		_implementation->enqueueEnterEvent(obj);
}

void ActiveArea::enqueueExitEvent(SceneObject* obj) {
	ActiveAreaImplementation* _implementation = static_cast<ActiveAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ENQUEUEEXITEVENT__SCENEOBJECT_);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else
		_implementation->enqueueExitEvent(obj);
}

void ActiveArea::notifyEnter(SceneObject* object) {
	ActiveAreaImplementation* _implementation = static_cast<ActiveAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYENTER__SCENEOBJECT_);
		method.addObjectParameter(object);

		method.executeWithVoidReturn();
	} else
		_implementation->notifyEnter(object);
}

void ActiveArea::notifyExit(SceneObject* object) {
	ActiveAreaImplementation* _implementation = static_cast<ActiveAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYEXIT__SCENEOBJECT_);
		method.addObjectParameter(object);

		method.executeWithVoidReturn();
	} else
		_implementation->notifyExit(object);
}

bool ActiveArea::isActiveArea() {
	ActiveAreaImplementation* _implementation = static_cast<ActiveAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISACTIVEAREA__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isActiveArea();
}

bool ActiveArea::isRegion() {
	ActiveAreaImplementation* _implementation = static_cast<ActiveAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISREGION__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isRegion();
}

bool ActiveArea::isCityRegion() {
	ActiveAreaImplementation* _implementation = static_cast<ActiveAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISCITYREGION__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isCityRegion();
}

bool ActiveArea::isNoBuildArea() {
	ActiveAreaImplementation* _implementation = static_cast<ActiveAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISNOBUILDAREA__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isNoBuildArea();
}

bool ActiveArea::containsPoint(float x, float y) {
	ActiveAreaImplementation* _implementation = static_cast<ActiveAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CONTAINSPOINT__FLOAT_FLOAT_);
		method.addFloatParameter(x);
		method.addFloatParameter(y);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->containsPoint(x, y);
}

float ActiveArea::getRadius2() {
	ActiveAreaImplementation* _implementation = static_cast<ActiveAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETRADIUS2__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getRadius2();
}

void ActiveArea::setNoBuildArea(bool val) {
	ActiveAreaImplementation* _implementation = static_cast<ActiveAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETNOBUILDAREA__BOOL_);
		method.addBooleanParameter(val);

		method.executeWithVoidReturn();
	} else
		_implementation->setNoBuildArea(val);
}

void ActiveArea::setMunicipalZone(bool val) {
	ActiveAreaImplementation* _implementation = static_cast<ActiveAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETMUNICIPALZONE__BOOL_);
		method.addBooleanParameter(val);

		method.executeWithVoidReturn();
	} else
		_implementation->setMunicipalZone(val);
}

void ActiveArea::setRadius(float r) {
	ActiveAreaImplementation* _implementation = static_cast<ActiveAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETRADIUS__FLOAT_);
		method.addFloatParameter(r);

		method.executeWithVoidReturn();
	} else
		_implementation->setRadius(r);
}

bool ActiveArea::isCampArea() {
	ActiveAreaImplementation* _implementation = static_cast<ActiveAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISCAMPAREA__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isCampArea();
}

void ActiveArea::setNoSpawnArea(bool val) {
	ActiveAreaImplementation* _implementation = static_cast<ActiveAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETNOSPAWNAREA__BOOL_);
		method.addBooleanParameter(val);

		method.executeWithVoidReturn();
	} else
		_implementation->setNoSpawnArea(val);
}

bool ActiveArea::isNoSpawnArea() {
	ActiveAreaImplementation* _implementation = static_cast<ActiveAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISNOSPAWNAREA__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isNoSpawnArea();
}

bool ActiveArea::isMunicipalZone() {
	ActiveAreaImplementation* _implementation = static_cast<ActiveAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISMUNICIPALZONE__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isMunicipalZone();
}

unsigned long long ActiveArea::getCellObjectID() {
	ActiveAreaImplementation* _implementation = static_cast<ActiveAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETCELLOBJECTID__);

		return method.executeWithUnsignedLongReturn();
	} else
		return _implementation->getCellObjectID();
}

void ActiveArea::setCellObjectID(unsigned long long celloid) {
	ActiveAreaImplementation* _implementation = static_cast<ActiveAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETCELLOBJECTID__LONG_);
		method.addUnsignedLongParameter(celloid);

		method.executeWithVoidReturn();
	} else
		_implementation->setCellObjectID(celloid);
}

DistributedObjectServant* ActiveArea::_getImplementation() {

	_updated = true;
	return _impl;
}

void ActiveArea::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	ActiveAreaImplementation
 */

ActiveAreaImplementation::ActiveAreaImplementation(DummyConstructorParameter* param) : SceneObjectImplementation(param) {
	_initializeImplementation();
}


ActiveAreaImplementation::~ActiveAreaImplementation() {
}


void ActiveAreaImplementation::finalize() {
}

void ActiveAreaImplementation::_initializeImplementation() {
	_setClassHelper(ActiveAreaHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void ActiveAreaImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<ActiveArea*>(stub);
	SceneObjectImplementation::_setStub(stub);
}

DistributedObjectStub* ActiveAreaImplementation::_getStub() {
	return _this.get();
}

ActiveAreaImplementation::operator const ActiveArea*() {
	return _this.get();
}

void ActiveAreaImplementation::lock(bool doLock) {
	_this.get()->lock(doLock);
}

void ActiveAreaImplementation::lock(ManagedObject* obj) {
	_this.get()->lock(obj);
}

void ActiveAreaImplementation::rlock(bool doLock) {
	_this.get()->rlock(doLock);
}

void ActiveAreaImplementation::wlock(bool doLock) {
	_this.get()->wlock(doLock);
}

void ActiveAreaImplementation::wlock(ManagedObject* obj) {
	_this.get()->wlock(obj);
}

void ActiveAreaImplementation::unlock(bool doLock) {
	_this.get()->unlock(doLock);
}

void ActiveAreaImplementation::runlock(bool doLock) {
	_this.get()->runlock(doLock);
}

void ActiveAreaImplementation::_serializationHelperMethod() {
	SceneObjectImplementation::_serializationHelperMethod();

	_setClassName("ActiveArea");

}

void ActiveAreaImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(ActiveAreaImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool ActiveAreaImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (SceneObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "ActiveArea.radius2") {
		TypeInfo<float >::parseFromBinaryStream(&radius2, stream);
		return true;
	}

	if (_name == "ActiveArea.noBuildArea") {
		TypeInfo<bool >::parseFromBinaryStream(&noBuildArea, stream);
		return true;
	}

	if (_name == "ActiveArea.municipalZone") {
		TypeInfo<bool >::parseFromBinaryStream(&municipalZone, stream);
		return true;
	}

	if (_name == "ActiveArea.cellObjectID") {
		TypeInfo<unsigned long long >::parseFromBinaryStream(&cellObjectID, stream);
		return true;
	}

	if (_name == "ActiveArea.noSpawnArea") {
		TypeInfo<bool >::parseFromBinaryStream(&noSpawnArea, stream);
		return true;
	}


	return false;
}

void ActiveAreaImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = ActiveAreaImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int ActiveAreaImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = SceneObjectImplementation::writeObjectMembers(stream);

	String _name;
	int _offset;
	uint32 _totalSize;
	_name = "ActiveArea.radius2";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<float >::toBinaryStream(&radius2, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "ActiveArea.noBuildArea";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<bool >::toBinaryStream(&noBuildArea, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "ActiveArea.municipalZone";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<bool >::toBinaryStream(&municipalZone, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "ActiveArea.cellObjectID";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<unsigned long long >::toBinaryStream(&cellObjectID, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "ActiveArea.noSpawnArea";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<bool >::toBinaryStream(&noSpawnArea, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);


	return _count + 5;
}

ActiveAreaImplementation::ActiveAreaImplementation() {
	_initializeImplementation();
	// server/zone/objects/area/ActiveArea.idl():  		radius2 = 0;
	radius2 = 0;
	// server/zone/objects/area/ActiveArea.idl():  		cellObjectID = 0;
	cellObjectID = 0;
	// server/zone/objects/area/ActiveArea.idl():  		noBuildArea = false;
	noBuildArea = false;
	// server/zone/objects/area/ActiveArea.idl():  		municipalZone = false;
	municipalZone = false;
	// server/zone/objects/area/ActiveArea.idl():  		noSpawnArea = false;
	noSpawnArea = false;
	// server/zone/objects/area/ActiveArea.idl():  		Logger.setLoggingName("ActiveArea");
	Logger::setLoggingName("ActiveArea");
}

void ActiveAreaImplementation::sendTo(SceneObject* player, bool doClose) {
}

bool ActiveAreaImplementation::isActiveArea() {
	// server/zone/objects/area/ActiveArea.idl():  		return true;
	return true;
}

bool ActiveAreaImplementation::isRegion() {
	// server/zone/objects/area/ActiveArea.idl():  		return false;
	return false;
}

bool ActiveAreaImplementation::isCityRegion() {
	// server/zone/objects/area/ActiveArea.idl():  		return false;
	return false;
}

bool ActiveAreaImplementation::isNoBuildArea() {
	// server/zone/objects/area/ActiveArea.idl():  		return noBuildArea;
	return noBuildArea;
}

float ActiveAreaImplementation::getRadius2() {
	// server/zone/objects/area/ActiveArea.idl():  		return radius2;
	return radius2;
}

void ActiveAreaImplementation::setNoBuildArea(bool val) {
	// server/zone/objects/area/ActiveArea.idl():  		noBuildArea = val;
	noBuildArea = val;
}

void ActiveAreaImplementation::setMunicipalZone(bool val) {
	// server/zone/objects/area/ActiveArea.idl():  		municipalZone = val;
	municipalZone = val;
}

void ActiveAreaImplementation::setRadius(float r) {
	// server/zone/objects/area/ActiveArea.idl():  		super.setRadius(r);
	SceneObjectImplementation::setRadius(r);
	// server/zone/objects/area/ActiveArea.idl():  		radius2 = r * r;
	radius2 = r * r;
}

bool ActiveAreaImplementation::isCampArea() {
	// server/zone/objects/area/ActiveArea.idl():  		return false;
	return false;
}

void ActiveAreaImplementation::setNoSpawnArea(bool val) {
	// server/zone/objects/area/ActiveArea.idl():  		noSpawnArea = val;
	noSpawnArea = val;
}

bool ActiveAreaImplementation::isNoSpawnArea() {
	// server/zone/objects/area/ActiveArea.idl():  		return noSpawnArea;
	return noSpawnArea;
}

bool ActiveAreaImplementation::isMunicipalZone() {
	// server/zone/objects/area/ActiveArea.idl():  		return municipalZone;
	return municipalZone;
}

unsigned long long ActiveAreaImplementation::getCellObjectID() {
	// server/zone/objects/area/ActiveArea.idl():  		return cellObjectID;
	return cellObjectID;
}

void ActiveAreaImplementation::setCellObjectID(unsigned long long celloid) {
	// server/zone/objects/area/ActiveArea.idl():  		cellObjectID = celloid;
	cellObjectID = celloid;
}

/*
 *	ActiveAreaAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


ActiveAreaAdapter::ActiveAreaAdapter(ActiveArea* obj) : SceneObjectAdapter(obj) {
}

void ActiveAreaAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_SENDTO__SCENEOBJECT_BOOL_:
		{
			sendTo(static_cast<SceneObject*>(inv->getObjectParameter()), inv->getBooleanParameter());
		}
		break;
	case RPC_ENQUEUEENTEREVENT__SCENEOBJECT_:
		{
			enqueueEnterEvent(static_cast<SceneObject*>(inv->getObjectParameter()));
		}
		break;
	case RPC_ENQUEUEEXITEVENT__SCENEOBJECT_:
		{
			enqueueExitEvent(static_cast<SceneObject*>(inv->getObjectParameter()));
		}
		break;
	case RPC_NOTIFYENTER__SCENEOBJECT_:
		{
			notifyEnter(static_cast<SceneObject*>(inv->getObjectParameter()));
		}
		break;
	case RPC_NOTIFYEXIT__SCENEOBJECT_:
		{
			notifyExit(static_cast<SceneObject*>(inv->getObjectParameter()));
		}
		break;
	case RPC_ISACTIVEAREA__:
		{
			resp->insertBoolean(isActiveArea());
		}
		break;
	case RPC_ISREGION__:
		{
			resp->insertBoolean(isRegion());
		}
		break;
	case RPC_ISCITYREGION__:
		{
			resp->insertBoolean(isCityRegion());
		}
		break;
	case RPC_ISNOBUILDAREA__:
		{
			resp->insertBoolean(isNoBuildArea());
		}
		break;
	case RPC_CONTAINSPOINT__FLOAT_FLOAT_:
		{
			resp->insertBoolean(containsPoint(inv->getFloatParameter(), inv->getFloatParameter()));
		}
		break;
	case RPC_GETRADIUS2__:
		{
			resp->insertFloat(getRadius2());
		}
		break;
	case RPC_SETNOBUILDAREA__BOOL_:
		{
			setNoBuildArea(inv->getBooleanParameter());
		}
		break;
	case RPC_SETMUNICIPALZONE__BOOL_:
		{
			setMunicipalZone(inv->getBooleanParameter());
		}
		break;
	case RPC_SETRADIUS__FLOAT_:
		{
			setRadius(inv->getFloatParameter());
		}
		break;
	case RPC_ISCAMPAREA__:
		{
			resp->insertBoolean(isCampArea());
		}
		break;
	case RPC_SETNOSPAWNAREA__BOOL_:
		{
			setNoSpawnArea(inv->getBooleanParameter());
		}
		break;
	case RPC_ISNOSPAWNAREA__:
		{
			resp->insertBoolean(isNoSpawnArea());
		}
		break;
	case RPC_ISMUNICIPALZONE__:
		{
			resp->insertBoolean(isMunicipalZone());
		}
		break;
	case RPC_GETCELLOBJECTID__:
		{
			resp->insertLong(getCellObjectID());
		}
		break;
	case RPC_SETCELLOBJECTID__LONG_:
		{
			setCellObjectID(inv->getUnsignedLongParameter());
		}
		break;
	default:
		throw Exception("Method does not exists");
	}
}

void ActiveAreaAdapter::sendTo(SceneObject* player, bool doClose) {
	(static_cast<ActiveArea*>(stub))->sendTo(player, doClose);
}

void ActiveAreaAdapter::enqueueEnterEvent(SceneObject* obj) {
	(static_cast<ActiveArea*>(stub))->enqueueEnterEvent(obj);
}

void ActiveAreaAdapter::enqueueExitEvent(SceneObject* obj) {
	(static_cast<ActiveArea*>(stub))->enqueueExitEvent(obj);
}

void ActiveAreaAdapter::notifyEnter(SceneObject* object) {
	(static_cast<ActiveArea*>(stub))->notifyEnter(object);
}

void ActiveAreaAdapter::notifyExit(SceneObject* object) {
	(static_cast<ActiveArea*>(stub))->notifyExit(object);
}

bool ActiveAreaAdapter::isActiveArea() {
	return (static_cast<ActiveArea*>(stub))->isActiveArea();
}

bool ActiveAreaAdapter::isRegion() {
	return (static_cast<ActiveArea*>(stub))->isRegion();
}

bool ActiveAreaAdapter::isCityRegion() {
	return (static_cast<ActiveArea*>(stub))->isCityRegion();
}

bool ActiveAreaAdapter::isNoBuildArea() {
	return (static_cast<ActiveArea*>(stub))->isNoBuildArea();
}

bool ActiveAreaAdapter::containsPoint(float x, float y) {
	return (static_cast<ActiveArea*>(stub))->containsPoint(x, y);
}

float ActiveAreaAdapter::getRadius2() {
	return (static_cast<ActiveArea*>(stub))->getRadius2();
}

void ActiveAreaAdapter::setNoBuildArea(bool val) {
	(static_cast<ActiveArea*>(stub))->setNoBuildArea(val);
}

void ActiveAreaAdapter::setMunicipalZone(bool val) {
	(static_cast<ActiveArea*>(stub))->setMunicipalZone(val);
}

void ActiveAreaAdapter::setRadius(float r) {
	(static_cast<ActiveArea*>(stub))->setRadius(r);
}

bool ActiveAreaAdapter::isCampArea() {
	return (static_cast<ActiveArea*>(stub))->isCampArea();
}

void ActiveAreaAdapter::setNoSpawnArea(bool val) {
	(static_cast<ActiveArea*>(stub))->setNoSpawnArea(val);
}

bool ActiveAreaAdapter::isNoSpawnArea() {
	return (static_cast<ActiveArea*>(stub))->isNoSpawnArea();
}

bool ActiveAreaAdapter::isMunicipalZone() {
	return (static_cast<ActiveArea*>(stub))->isMunicipalZone();
}

unsigned long long ActiveAreaAdapter::getCellObjectID() {
	return (static_cast<ActiveArea*>(stub))->getCellObjectID();
}

void ActiveAreaAdapter::setCellObjectID(unsigned long long celloid) {
	(static_cast<ActiveArea*>(stub))->setCellObjectID(celloid);
}

/*
 *	ActiveAreaHelper
 */

ActiveAreaHelper* ActiveAreaHelper::staticInitializer = ActiveAreaHelper::instance();

ActiveAreaHelper::ActiveAreaHelper() {
	className = "ActiveArea";

	Core::getObjectBroker()->registerClass(className, this);
}

void ActiveAreaHelper::finalizeHelper() {
	ActiveAreaHelper::finalize();
}

DistributedObject* ActiveAreaHelper::instantiateObject() {
	return new ActiveArea(DummyConstructorParameter::instance());
}

DistributedObjectServant* ActiveAreaHelper::instantiateServant() {
	return new ActiveAreaImplementation();
}

DistributedObjectAdapter* ActiveAreaHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ActiveAreaAdapter(static_cast<ActiveArea*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

