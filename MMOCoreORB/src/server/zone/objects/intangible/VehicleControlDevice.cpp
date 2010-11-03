/*
 *	server/zone/objects/intangible/VehicleControlDevice.cpp generated by engine3 IDL compiler 0.60
 */

#include "VehicleControlDevice.h"

#include "server/zone/objects/intangible/IntangibleObject.h"

#include "server/zone/objects/creature/VehicleObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

/*
 *	VehicleControlDeviceStub
 */

VehicleControlDevice::VehicleControlDevice() : ControlDevice(DummyConstructorParameter::instance()) {
	VehicleControlDeviceImplementation* _implementation = new VehicleControlDeviceImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

VehicleControlDevice::VehicleControlDevice(DummyConstructorParameter* param) : ControlDevice(param) {
}

VehicleControlDevice::~VehicleControlDevice() {
}


void VehicleControlDevice::storeObject(PlayerCreature* player) {
	VehicleControlDeviceImplementation* _implementation = (VehicleControlDeviceImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->storeObject(player);
}

void VehicleControlDevice::generateObject(PlayerCreature* player) {
	VehicleControlDeviceImplementation* _implementation = (VehicleControlDeviceImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->generateObject(player);
}

int VehicleControlDevice::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	VehicleControlDeviceImplementation* _implementation = (VehicleControlDeviceImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(player);
		method.addByteParameter(selectedID);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->handleObjectMenuSelect(player, selectedID);
}

void VehicleControlDevice::destroyObjectFromDatabase(bool destroyContainedObjects) {
	VehicleControlDeviceImplementation* _implementation = (VehicleControlDeviceImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addBooleanParameter(destroyContainedObjects);

		method.executeWithVoidReturn();
	} else
		_implementation->destroyObjectFromDatabase(destroyContainedObjects);
}

int VehicleControlDevice::canBeDestroyed(PlayerCreature* player) {
	VehicleControlDeviceImplementation* _implementation = (VehicleControlDeviceImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addObjectParameter(player);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->canBeDestroyed(player);
}

DistributedObjectServant* VehicleControlDevice::_getImplementation() {
	return _impl;}

void VehicleControlDevice::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;}

/*
 *	VehicleControlDeviceImplementation
 */

VehicleControlDeviceImplementation::VehicleControlDeviceImplementation(DummyConstructorParameter* param) : ControlDeviceImplementation(param) {
	_initializeImplementation();
}


VehicleControlDeviceImplementation::~VehicleControlDeviceImplementation() {
}


void VehicleControlDeviceImplementation::finalize() {
}

void VehicleControlDeviceImplementation::_initializeImplementation() {
	_setClassHelper(VehicleControlDeviceHelper::instance());

	_serializationHelperMethod();
}

void VehicleControlDeviceImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (VehicleControlDevice*) stub;
	ControlDeviceImplementation::_setStub(stub);
}

DistributedObjectStub* VehicleControlDeviceImplementation::_getStub() {
	return _this;
}

VehicleControlDeviceImplementation::operator const VehicleControlDevice*() {
	return _this;
}

void VehicleControlDeviceImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void VehicleControlDeviceImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void VehicleControlDeviceImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void VehicleControlDeviceImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void VehicleControlDeviceImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void VehicleControlDeviceImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void VehicleControlDeviceImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void VehicleControlDeviceImplementation::_serializationHelperMethod() {
	ControlDeviceImplementation::_serializationHelperMethod();

	_setClassName("VehicleControlDevice");

}

VehicleControlDeviceImplementation::VehicleControlDeviceImplementation() {
	_initializeImplementation();
	// server/zone/objects/intangible/VehicleControlDevice.idl(61):  		Logger.setLoggingName("VehicleControlDevice");
	Logger::setLoggingName("VehicleControlDevice");
	// server/zone/objects/intangible/VehicleControlDevice.idl(62):  		Logger.setLogging(false);
	Logger::setLogging(false);
	// server/zone/objects/intangible/VehicleControlDevice.idl(63):  		Logger.setGlobalLogging(true);
	Logger::setGlobalLogging(true);
}

int VehicleControlDeviceImplementation::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	// server/zone/objects/intangible/VehicleControlDevice.idl(71):  		Logger.info("selected call");
	Logger::info("selected call");
	// server/zone/objects/intangible/VehicleControlDevice.idl(73):  
	if (selectedID == RadialOptions::VEHICLE_GENERATE){
	// server/zone/objects/intangible/VehicleControlDevice.idl(75):  
	if (ControlDeviceImplementation::controlledObject.getForUpdate() == NULL){
	// server/zone/objects/intangible/VehicleControlDevice.idl(76):  				Logger.error("null controlled object in vehicle control device");
	Logger::error("null controlled object in vehicle control device");
	// server/zone/objects/intangible/VehicleControlDevice.idl(77):  				return 1;
	return 1;
}

	else {
	// server/zone/objects/intangible/VehicleControlDevice.idl(79):  				this.generateObject(player);
	_this->generateObject(player);
}
}

	else 	// server/zone/objects/intangible/VehicleControlDevice.idl(81):  		return 
	if (selectedID == RadialOptions::VEHICLE_STORE){
	// server/zone/objects/intangible/VehicleControlDevice.idl(82):  
	if (ControlDeviceImplementation::controlledObject.getForUpdate() == NULL){
	// server/zone/objects/intangible/VehicleControlDevice.idl(83):  				Logger.error("null controlled object in vehicle control device");
	Logger::error("null controlled object in vehicle control device");
	// server/zone/objects/intangible/VehicleControlDevice.idl(84):  				return 1;
	return 1;
}

	else {
	// server/zone/objects/intangible/VehicleControlDevice.idl(86):  
	if (ControlDeviceImplementation::status == 1 && !ControlDeviceImplementation::controlledObject.getForUpdate()->isInQuadTree()){
	// server/zone/objects/intangible/VehicleControlDevice.idl(87):  					this.generateObject(player);
	_this->generateObject(player);
}

	else {
	// server/zone/objects/intangible/VehicleControlDevice.idl(89):  					this.storeObject(player);
	_this->storeObject(player);
}
}
}
	// server/zone/objects/intangible/VehicleControlDevice.idl(94):  0;
	return 0;
}

/*
 *	VehicleControlDeviceAdapter
 */

VehicleControlDeviceAdapter::VehicleControlDeviceAdapter(VehicleControlDeviceImplementation* obj) : ControlDeviceAdapter(obj) {
}

Packet* VehicleControlDeviceAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		storeObject((PlayerCreature*) inv->getObjectParameter());
		break;
	case 7:
		generateObject((PlayerCreature*) inv->getObjectParameter());
		break;
	case 8:
		resp->insertSignedInt(handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	case 9:
		destroyObjectFromDatabase(inv->getBooleanParameter());
		break;
	case 10:
		resp->insertSignedInt(canBeDestroyed((PlayerCreature*) inv->getObjectParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

void VehicleControlDeviceAdapter::storeObject(PlayerCreature* player) {
	((VehicleControlDeviceImplementation*) impl)->storeObject(player);
}

void VehicleControlDeviceAdapter::generateObject(PlayerCreature* player) {
	((VehicleControlDeviceImplementation*) impl)->generateObject(player);
}

int VehicleControlDeviceAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	return ((VehicleControlDeviceImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

void VehicleControlDeviceAdapter::destroyObjectFromDatabase(bool destroyContainedObjects) {
	((VehicleControlDeviceImplementation*) impl)->destroyObjectFromDatabase(destroyContainedObjects);
}

int VehicleControlDeviceAdapter::canBeDestroyed(PlayerCreature* player) {
	return ((VehicleControlDeviceImplementation*) impl)->canBeDestroyed(player);
}

/*
 *	VehicleControlDeviceHelper
 */

VehicleControlDeviceHelper* VehicleControlDeviceHelper::staticInitializer = VehicleControlDeviceHelper::instance();

VehicleControlDeviceHelper::VehicleControlDeviceHelper() {
	className = "VehicleControlDevice";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void VehicleControlDeviceHelper::finalizeHelper() {
	VehicleControlDeviceHelper::finalize();
}

DistributedObject* VehicleControlDeviceHelper::instantiateObject() {
	return new VehicleControlDevice(DummyConstructorParameter::instance());
}

DistributedObjectServant* VehicleControlDeviceHelper::instantiateServant() {
	return new VehicleControlDeviceImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* VehicleControlDeviceHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new VehicleControlDeviceAdapter((VehicleControlDeviceImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

